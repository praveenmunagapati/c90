#include <stdio.h>
/*
        d) Write a program for display values reverse order from an array using a pointer.
*/

int main() {
    int array[5] = {8,6,5,4,9};
    int *parray = (array+sizeof(array)/sizeof(int)-1);
    printf("%p\n",&array[4]);
    printf("%p\n",parray);
    for (int i = 0; i < 5; ++i) {
        //printf("%d\t",*(parray - i));
        printf("%d\t",*parray--);
    }

    return 0;
}