#include <stdio.h>

int fact(int n) {
    printf("Entering: fact(%d)\n", n);

    if (n == 0)
        return 1;

    int result = n * fact(n - 1);

    printf("Returning: fact(%d) = %d\n", n, result);
    return result;
}

int main() {
    printf("Answer = %d\n", fact(5));
    return 0;
}