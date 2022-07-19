#include"book_bdb.h"
#include"user_bdb.h"
#include"myutil.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"dlist.h"
#include<threads.h>
long countStudent = 0,countStaff = 0, CountLibrarian = 0;
long Studbook = 0,Staffbook = 0, Librarianbook = 0;
int stud[32],staf[32],libr[32];
void dateNow(user_t* user)
{    
    time_t t = time(NULL);    
    struct tm t1 = *localtime(&t);
    user->date[user->numOfBooks-1].tm_day = t1.tm_mday;
    user->date[user->numOfBooks-1].tm_mon = t1.tm_mon+1;
    user->date[user->numOfBooks-1].tm_year =t1.tm_year+1900;
   // *(date)=tm;    
    // sprintf(myDate,"%02d/%02d/%d",tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);    
    // strcpy(b.date,myDate);
}
int fine(user_t* user,int pos)
{   
    time_t t = time(NULL);    
    struct tm t1 = *localtime(&t);
    double count = 0;
    count = ((365*(t1.tm_year+1900)) +(30*(t1.tm_mon+1))+t1.tm_mday) - ((365*user->date[pos].tm_year) +(30*user->date[pos].tm_mon)+user->date[pos].tm_day) ;
    printf("\nNo of days %f\n",count);
    if(count >1)
    {
        count=count-1;
        count = count*5;
        return count;
    }
    return 0;
}
void create_book(){
    system("clear");
    book_t *books=(book_t *)malloc(sizeof(book_t));
    memset(books,0,sizeof(book_t));
    printf("Enter book id:"); 
    scanf("%d",&books->bookId);
	printf("Enter ISBN:"); 
    scanf("%d",&books->bookISBN);
    printf("Enter author name:"); 
    clear_input_buffer(); 
    scanf("%[^\n]s",books->author);
    printf("Enter book title:"); 
    clear_input_buffer();
    scanf("%[^\n]s",books->bookTitle);
    printf("Enter publication:"); 
    clear_input_buffer();
    scanf("%[^\n]s",books->publication);
    printf("Enter number of copies:"); 
    scanf("%d",&books->numOfCopies);
    printf("Enter price:"); 
    scanf("%lf",&books->price);
    
    book_insert(books);
    free(books);
    
}
void deleteBook()
{
    book_t book = {};
    int id=0;
    printf("Enter book id for delete:"); 
    scanf("%d",&id);  
    book_readById(&book,id);  
    if(book.bookId == id)
    {
        printf("book id:%d\n",book.bookId);
        printf("book ISBN:%d\n",book.bookISBN);
        printf("author name:%s\n",book.author);
        printf("book title:%s\n",book.bookTitle);
        printf("publication:%s\n",book.publication);
        printf("number of copies:%d\n",book.numOfCopies);
        printf("price:%.2lf\n\n\n",book.price);
        book_delete(id);
        printf("\nbookid %d is deleted successfully.\n",book.bookId);
    }
    else
        printf("\n Not found\n");
}
void book_edit(){
    system("clear");
    book_t book = {};
    int id;
    printf("Enter book id to find:"); scanf("%d",&id);
    book_readById(&book,id);
    
    if(book.bookId == id)
    {
        printf("\n\n\nThe searched book(Binary File):\n");    

        printf("book id:%d\n",book.bookId);
        printf("book ISBN:%d\n",book.bookISBN);
        printf("author name:%s\n",book.author);
        printf("book title:%s\n",book.bookTitle);
        printf("publication:%s\n",book.publication);
        printf("number of copies:%d\n",book.numOfCopies);
        printf("price:%.2lf\n\n\n",book.price);
        int menu;
        printf("\n\nPick Choice to edit\n");
        printf("\t1-book ISBN, 2-author name,3-book title\n");
        printf("\t4.publication 5.number of copies 6.price \n"); 
        printf("0.exit \nYour Choice:"); scanf("%d",&menu);
        printf("\n");
        if(1==menu){
            printf("Enter ISBN:"); 
            scanf("%d",&book.bookISBN);

        }else if(2==menu){
            printf("Enter author name:"); 
            clear_input_buffer(); 
            scanf("%[^\n]s",book.author);
        }
        else if(3==menu)
        {
            printf("Enter book title:"); 
            clear_input_buffer();
            scanf("%[^\n]s",book.bookTitle);
        }
        if(4==menu)
        {
            printf("Enter publication:"); 
            clear_input_buffer();
            scanf("%[^\n]s",book.publication);
        }
        else if(5==menu)
        {
            printf("Enter number of copies:"); 
            scanf("%d",&book.numOfCopies);
        }
        else if(6==menu)
        {
            printf("Enter price:"); 
            scanf("%lf",&book.price);
        }
        else{
            printf("closing edit....\n");
        }  
        book_update(book);	   
        printf("bookid %d is updated successfully.\n",book.bookId);
    }
    else
        printf("book id is not found.\n");
}
void printBook(book_t* addr){
   
     
        printf("book id:%d\n",addr->bookId);
        printf("author name:%s\n",addr->author);
        printf("book title:%s\n",addr->bookTitle);
        printf("publication:%s\n",addr->publication);
        printf("number of copies:%d\n",addr->numOfCopies);
        printf("price:%.2lf\n\n\n",addr->price);

   
}
void list_books(){
    system("clear");

    book_t *books= (book_t *)malloc(20*sizeof(book_t));
    memset(books,0,sizeof(book_t)*20);
    int count = 0;
    book_readAll(books,&count);
    printf("\nBooks\n");
    for(int I = 0; I < count; I++)
        insertNodeBack(books[I]);
    doTraversal(printBook);
    free(books);
    destroy();
    // for(int I = 0; I < count; I++){
    //     printf("%d)\n",I);
    //     printf("book id:%d\n",books[I].bookId);
    //     printf("author name:%s\n",books[I].author);
    //     printf("book title:%s\n",books[I].bookTitle);
    //     printf("publication:%s\n",books[I].publication);
    //     printf("number of copies:%d\n",books[I].numOfCopies);
    //     printf("price:%.2lf\n\n\n",books[I].price);
    // }
    // free(books);
}
void book_menu()
{
    system("clear");
    int menu;
        printf("\n\nPick Choice\n");
        printf("\t1-Create book, 2-Read All,3-delete book\n");
        printf("\t4.Edit book 0-Exit\n"); 
        printf("Your Choice:"); scanf("%d",&menu);
        
        printf("\n");
        if(1==menu){
             create_book();
        }else if(2==menu){
             list_books();
        }
        else if(3==menu)
        {
            deleteBook();
        }
        else if(4==menu)
        {
            book_edit();
        }
        else{
            printf("Invalid choose....\n");
        }
       // clear_input_buffer();
   
}
void issueBook(user_t* user)
{
    system("clear");
    printf("\nListting Books By id ");
    list_books();
    int id;
    printf("\nSelect the book by id ");
    scanf("%d",&id);
    book_t book = {};  
    book_readById(&book,id);
    if(book.bookId == id)
    {
        if(book.numOfCopies != 0)
            {
                if((user->numOfBooks != user->maxBook))
                {
                    book.numOfCopies--;
                    user->numOfBooks++;
                    user->bookIssued[user->numOfBooks-1] = book.bookId ;
                    dateNow(user);
                   // printf("\n%02d/%02d/%d",user->date[user->numOfBooks-1].tm_day,
                    //user->date[user->numOfBooks-1].tm_mon,user->date[user->numOfBooks-1].tm_year);
                    book_update(book);
                    user_update(user);
                }
                else 
                    printf("\ncant issue books \n");
            }
            else
                printf("\nNo books left\n");
    }
    else
        printf("\nInvalid book id\n");
    
}
void returnBook(user_t* user)
{
    system("clear");
    if(user->numOfBooks != 0)
    {
        printf("number of books:%d\n",user->numOfBooks);
        printf("\nissued books\n");
        for(int i=0 ;i<user->numOfBooks;i++)
        {
            printf("\nBookID :%d  Issue date :%02d/%02d/%d",user->bookIssued[i],user->date[i].tm_day,
                    user->date[i].tm_mon,user->date[i].tm_year);         
        }
        int id;
        printf("\nSelect the book to return by id ");
        scanf("%d",&id);
        book_t book = {};  
        book_readById(&book,id);
        int pos = -1;
        if(book.bookId == id)
        {
            for(int i=0;i<user->numOfBooks;i++)
            {
                if(user->bookIssued[i] == id)
                    {
                        pos = i;
                        break;
                    }
            }
            if(pos>=0)
            {
                system("clear");
                int fine_user = 0;
                fine_user =fine(user,pos);
                printf("\nFine Rs %d/-\n",fine_user);
                for(int i = pos ;i <user->numOfBooks;i++)
                    {
                        user->bookIssued[i] = user->bookIssued[i+1];
                        user->date[i] = user->date[i+1];
                    }
                user->numOfBooks--;
                book.numOfCopies++;
                book_update(book);
                user_update(user);
                printf("\nissued books left\n");
                for(int i=0 ;i<user->numOfBooks;i++)
                {
                    printf("\nBookID :%d  Issue date :%02d/%02d/%d",user->bookIssued[i],user->date[i].tm_day,
                            user->date[i].tm_mon,user->date[i].tm_year);         
                }
            }
            else
            {
                printf("\nInvalid book id");
            }
        }
        else
            printf("\nInvalid book id\n");
    }
    else
       printf("\nNO book to Return\n");     
}
void addUser()
{
    system("clear");
    user_t *user=(user_t *)malloc(sizeof(user_t));
    memset(user,0,sizeof(user_t));
    printf("Enter User id:"); 
    scanf("%d",&user->userId);
	printf("Enter Librarian/Staff/Student(2/1/0):"); 
    scanf("%d",&user->usertype);
    printf("Enter User Name:"); 
    clear_input_buffer(); 
    scanf("%[^\n]s",user->userName);
    printf("Enter new password:"); 
    clear_input_buffer(); 
    scanf("%[^\n]s",user->password);
    printf("Enter Department Name:"); 
    clear_input_buffer(); 
    scanf("%[^\n]s",user->userDept);
   // clear_input_buffer();
    user->numOfBooks = 0;
    if(user->usertype == 2 )
        user->maxBook = 4;
    else if(user->usertype == 1)
        user->maxBook = 4;
    else
        user->maxBook = 2;
    user_insert(user);
    free(user);

    
}
void issuedBooks()
{
    system("clear");
    user_t *users= (user_t *)malloc(20*sizeof(user_t));
    int count = 0;
    user_readAll(users,&count);
    printf("\nIssued Books\n");
    for(int I = 0; I < count; I++){
        printf("\n%d)\n",I);
        printf("user id:%d\n",users[I].userId);
        printf("User name:%s\n",users[I].userName);
        printf("Department:%s\n",users[I].userDept);
        if(users[I].usertype == 1)
            printf("User type :Staff\n");
        else if(users[I].usertype == 0)
            printf("User type :Student\n");
        else if(users[I].usertype == 2)
            printf("User type :Librarian\n");
        printf("number of books:%d\n",users[I].numOfBooks);
        for(int i=0 ;i<users[I].numOfBooks;i++)
        {
            printf("\nBookID :%d  Issue date :%02d/%02d/%d",users[I].bookIssued[i],users[I].date[i].tm_day,
                    users[I].date[i].tm_mon,users[I].date[i].tm_year);
            
                    
        }
    
    }
    free(users);
}
void userLogin(user_t user)
{
     int menu=1;
     while(menu >= 1 && menu<=2)
        {
            printf("\n\nPick Choice\n");
            printf("\t1-Issue Books, 2-Return book\n");
            printf("\t0-Exit\n"); 
            printf("Your Choice:"); scanf("%d",&menu);
            
            printf("\n");
            if(1==menu){
                issueBook(&user);
            }else if(2==menu){
                returnBook(&user);
            }
            else if(0==menu){
                    printf("Log out....\n");
                }
            else{
                printf("Invalid choose....\n");
            }
        }
}
void process();
void libLogin(user_t lib)
{
     int menu=1;
     while(menu >= 1 && menu<=4)
            {
                process();
                printf("\n\nPick Choice\n");
                printf("\t1-Issue Books\n\t2.Return book\n\t3-Add/Edit/Delete book\n");
                printf("\t4.Issued books\n\t0-Exit\n"); 
                printf("Your Choice:"); scanf("%d",&menu);
                
                 printf("\n");
                if(1==menu){
                    issueBook(&lib);
                }
                else if(2==menu){
                    returnBook(&lib);
                }else if(3==menu){
                    book_menu();
                }
                else if(4==menu){
                    issuedBooks();
                }
                else if(0==menu){
                    printf("Log out....\n");
                }
                else{
                    printf("Invalid choose....\n");
                }
            }
}
void login()
{
    user_t user = {};
    int id=0;
    char password[256];
    system("clear");
    printf("Enter user id:"); 
    scanf("%d",&id);  
    user_readById(&user,id); 
    if(user.userId == id)
    {
        system("clear");
        printf("\n\nWelcome %s ",user.userName);
        if(user.usertype == 1)
            printf("(Staff)\n");
        else if(user.usertype == 0)
            printf("(Student)\n");
        else if(user.usertype == 2)
            printf("(Librarian)\n");
        printf("Enter password\n");
        scanf("%s",password); 
        if(strcmp(password,user.password)==0)
        {
            if((user.usertype == 1)||(user.usertype == 0))
                  userLogin(user);
            else if((user.usertype == 2))
                  libLogin(user);
        }
        else
            printf("\nInvalid Password");
    }
    else
        printf("\nInvalid Id");
}
void doCountstud()
{
	for(int i=0;i<countStudent;i++)    
	        {       
	        	Studbook += stud[i]; 
	        } 
}
int doCountstud_routine()
{
	doCountstud();
	return 0;
}
void doCountstaff()
{
	long counterTemp = 0;
	for(int i=0;i<countStaff;i++)    
	        {       
	        	Staffbook += staf[i]; 
	        } 
}
int doCountstaff_routine()
{
	doCountstaff();
	return 0;
}
void doCountlib()
{
	long counterTemp = 0;
	for(int i=0;i<CountLibrarian;i++)    
	        {       
	        	Librarianbook += libr[i]; 
	        } 
}
int doCountlib_routine()
{
	doCountlib();
	return 0;
}
//long countStudent = 0,countStaff = 0, CountLibrarian = 0;
//int stud[32],staf[32],libr[32];
//long Studbook = 0,Staffbook = 0, Librarianbook = 0;
void process()
{
    countStudent = 0;
    countStaff = 0;
    CountLibrarian = 0;
    Studbook = 0;
    Staffbook = 0;
    Librarianbook = 0;
    //stud[32],staf[32],libr[32]
    memset(stud,0,sizeof(int)*32);
    memset(staf,0,sizeof(int)*32);
    memset(libr,0,sizeof(int)*32);
	thrd_t th1, th2,th3; 
    user_t *users= (user_t *)malloc(20*sizeof(user_t));
    int count = 0;
    user_readAll(users,&count);
    for(int I = 0; I < count; I++)
    {
        if(users[I].usertype == 1)
        {
            countStaff++;
            staf[countStaff-1] = users[I].numOfBooks;
        }
        else if(users[I].usertype == 0)
        {
            countStudent++;
            stud[countStudent-1] = users[I].numOfBooks;
        }
        else if(users[I].usertype == 2)
         {
            CountLibrarian++;
            libr[CountLibrarian-1] = users[I].numOfBooks;
        }
    }
    free(users);
        	thrd_create(&th1,doCountstud_routine,NULL); 
        	thrd_create(&th2,doCountstaff_routine,NULL);
            thrd_create(&th3,doCountlib_routine,NULL);       
        	thrd_join(th1,NULL);   
        	thrd_join(th2,NULL);
            thrd_join(th3,NULL);
            printf("\nTotal books issued");
        	printf("\nStudents = %ld\tStaff = %ld\tLibrarian =%ld\n",Studbook,Staffbook, Librarianbook);     
}
int main(){
    int menu;
    do{
        system("clear");
        printf("\n\nPick Choice\n");
        printf("\t1.Login\n");
        printf("\t2.Add user\n\t0-Exit\n"); 
        printf("Your Choice:"); scanf("%d",&menu);
        
        printf("\n");
        if(1==menu){
            login();
        }else if(2==menu){
            addUser();
        }
        else if(0==menu){
            printf("Shutting down the app....\n");
        }
        else{
            printf("Invalid choose....\n");
        }
        clear_input_buffer();
    }
    while(((1<=menu) && (menu<=4)));
	return EXIT_SUCCESS;
}
