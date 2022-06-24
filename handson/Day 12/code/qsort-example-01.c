#include <stdio.h>
#include <stdlib.h>
 
int compare_number(const void* a, const void* b)
{
    short first = *(const short*)a;
    short second = *(const short*)b;
    
    //asc
    if (first < second) return -1;
    if (first > second) return 1;
    return 0;
    
    // //or 
    //return first - second; // equivalent    10-8    8-10    10-10
    
    //desc
    /*
    if (first > second) return -1;
    if (first < second) return 1;
    return 0;
    */
    // //or 
    //return second - first;
}
 
int main(void)
{
    short numbers[] = {10,8,5,3,7,9,4};
    int size = 7;
 
    qsort(numbers, size, sizeof(short), compare_number);
 
    for (int i = 0; i < size; i++) {
        printf("%hd ", numbers[i]);
    }
 
    printf("\n");
    
    return EXIT_SUCCESS;
}