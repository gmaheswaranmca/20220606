#include<stdio.h>
    void swapAddr(double** firstAddrAddr, double** secondAddrAddr);
    void swapAddr(double** firstAddrAddr, double** secondAddrAddr){
        double* t = (*firstAddrAddr);
        (*firstAddrAddr) = (*secondAddrAddr);
        (*secondAddrAddr) = t;
    }

    int main(){
        double f = 1.0;
        double s = 1.1;
        
        double* addrOne = &f;
        double* addrTwo = &s;
        
        printf("%p %p %.2lf %.2lf\n",addrOne,addrTwo,(*addrOne),(*addrTwo)); //addr1 addr2 1.00 1.10
        swapAddr(&addrOne,&addrTwo);
        printf("%p %p %.2lf %.2lf\n",addrOne,addrTwo,(*addrOne),(*addrTwo)); //addr2 addr1 1.10 1.00
        return 0;
    }