#include<stdio.h>
// a function that calls itself is a recursive function
void infinitefoo(void) {
    printf("infinite recursion stack explodes\n");
    infinitefoo();
}
void controlledfoo(int i) {
    if (i==0)
        return;
    printf("%d\n",i);
    controlledfoo(--i);
}
int factorial(int i) {
    if (i==1) {
        return 1;
    }
    return i * factorial(i-1);
}
void linearrecursive(int array[],int key,int i) {

        if (array[i]==key) {
            printf("key found at index %d\n",i);
            return;
        }
        else {
            linearrecursive(array,key,i+1);
        }
}

// Function to find sum using recursion
int sumArray(int arr[], int n) {
    // Base Case: If size is 0 or less, stop and return 0
    if (n <= 0) {
        return 0;
    }
    // Recursive Step: Add the last element to the sum of the remaining array
    return arr[n - 1] + sumArray(arr, n - 1);
}

// Function to calculate string length recursively
int stringLength(char *str) {
    // Base Case: If the current character is the null terminator, length is 0
    if (*str == '\0') {
        return 0;
    }
    // Recursive Step: Count 1 for the current character, then shift the pointer forward
    return 1 + stringLength(str + 1);
}

int main(void) {
    setbuf(stdout, 0);
    //UNIT - IV: Recursion: The Nature of Recursion,
    //Tracing a Recursive Function, Recursive Mathematical Functions,
    //Recursive Functions with Array and String Parameters

    //infinitefoo();
    //controlledfoo(10);
    //printf("%d\n",factorial(5));

    // int array[10] = {1,2,3,4,5,6,7,8,9,10};
    // int mid = (sizeof(array) / sizeof(int))/2;
    // printf("%d\n",mid);
    // int key = 10;
    // int low = 0;
    // int high = sizeof(array) / sizeof(int);
    // while (low<high) {
    //     if (array[mid]==key) {
    //         printf("key found at index %d\n",mid);
    //         break;
    //     }
    //     if (array[mid] > key) {
    //         high = mid-1;
    //         mid = (low + high) / 2;
    //     }else{
    //         low = mid+1;
    //         mid = (low + high) / 2;
    //     }
    // }
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    int key = 5;
    int index = 0;
    linearrecursive(array,key,index);
    printf("%d\n",sumArray(array,10));
    printf("%d\n",stringLength("array"));
    return 0;
}