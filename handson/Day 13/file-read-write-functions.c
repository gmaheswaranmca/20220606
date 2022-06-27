//fscanf,fprint - to read/write from/into file 
//fgets,fputs - to read/write string from/into file 
//fgetc,fputc - to read/write char from/into file 
//  with stdin and stdout FILE streams for learning 
//  we used input buffer clear for reading char/string after number data reading 
#include<stdio.h>
#include<stdlib.h>
void clear_input_buffer(void){
    while(getchar() != '\n');
}
int main(){
    double salary;
    fprintf(stdout,"Enter salary:");
    fscanf(stdin,"%lf",&salary);
    fprintf(stdout,"The salary we read is : %.2lf\n",salary);
    
    //before reading the string/char after reading the number
    //clear the input buffer   
    char name[256];
    fprintf(stdout, "\nEnter name:");
    clear_input_buffer(); //after reading number, to read char/string, use this function call 
    fgets(name,256,stdin);
    fputs("The read string is ",stdout);
    fputs(name,stdout);
    fputs("\n",stdout);
    
    fputs("\nEnter gender:(M-male, F-Female, T-transgender):",stdout);
    char gender = fgetc(stdin);
    fputs("The given gender is ", stdout);
    fputc(gender, stdout);
    
    return EXIT_SUCCESS;
}