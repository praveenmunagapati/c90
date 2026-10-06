#include<stdio.h>


int main(void) {
    setbuf(stdout, 0);
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    int mid = (sizeof(array) / sizeof(int))/2;
    printf("%d\n",mid);
    int key = 10;
    int low = 0;
    int high = sizeof(array) / sizeof(int);
    while (low<high) {
        if (array[mid]==key) {
            printf("key found at index %d\n",mid);
            break;
        }
        if (array[mid] > key) {
            high = mid-1;
            mid = (low + high) / 2;
        }else{
            low = mid+1;
            mid = (low + high) / 2;
        }
    }

    return 0;
}