
#include <stdio.h>

void indent(int d) {
    for (int i = 0; i < d; i++)
        printf("  ");
}

int fact(int n, int d) {
    indent(d);
    printf("CALL: fact(%d)\n", n);

    if (n == 0) {
        indent(d);
        printf("BASE CASE: return 1\n");
        return 1;
    }

    indent(d);
    printf("CALLING fact(%d)\n", n - 1);

    int x = fact(n - 1, d + 1);

    indent(d);
    printf("BACK: fact(%d) returned %d\n", n - 1, x);

    int result = n * x;

    indent(d);
    printf("CALCULATE: %d * %d = %d\n", n, x, result);

    indent(d);
    printf("RETURN: %d\n", result);

    return result;
}

int main() {
    int answer = fact(5, 0);
    printf("\nFINAL ANSWER = %d\n", answer);
    return 0;
}
