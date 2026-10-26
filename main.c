#include <stdio.h>

void fabinacci(int a , int b) {
    if (b>1000) {
        return ;
    }
    int fabi = a + b;
    printf("%d\t",fabi);
    fabinacci(b,fabi);

}

int main() {
    // int a = 0;
    // int b = 1;
    // int fabi = a + b;
    // printf("%d\t",a);
    // printf("%d\t",b);
    // while (fabi<100) {
    //     printf("%d\t",fabi);
    //     a = b;
    //     b = fabi;
    //     fabi = a+b;
    // }
    fabinacci(0,1);


    return 0;
}