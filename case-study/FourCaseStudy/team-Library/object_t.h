#pragma once
struct _book_t{
 int bookId;
 int bookISBN;
 char author[256];
 char bookTitle[256];
 char publication[256];
 int numOfCopies;
 double price;
};
typedef struct _book_t book_t;
struct _date_t{
    int tm_day,tm_mon,tm_year;
};
typedef struct _date_t date_t;
struct _user_t{
 int userId;
 int usertype;
 char userName[256];
 char password[256];
 char userDept[256];
 int numOfBooks;
 int maxBook;
 int bookIssued[4];
 date_t date[4];
};
typedef struct _user_t user_t;

