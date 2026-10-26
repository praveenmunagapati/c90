#include <stdio.h>

int f(int n) {
    return n ? n * f(n - 1) : 1;
}

int main() {
    printf("%d", f(5));
}