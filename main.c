#include <stdio.h>
/*
        c) Write a program for reading elements using a pointer into an array
           and display the values using the array. */

int main() {
    int array[5];
    int *parray = array;
    printf("%p\n",parray);
    printf("%p\n",array);
    scanf("%d",parray);
    scanf("%d",parray+1);
    scanf("%d",parray+2);
    scanf("%d",parray+3);
    scanf("%d",parray+4);

    printf("%d\n",array[0]);
    printf("%d\n",array[1]);
    printf("%d\n",array[2]);
    printf("%d\n",array[3]);
    printf("%d\n",array[4]);
    for (int i = 0; i < 5; ++i) {
        printf("enter a number for array at index %d :",i);
        scanf("%d",(parray+i));

    }
    for (int i = 0; i < 5; ++i) {
        printf("%d\t",array[i]);

    }

    return 0;
}