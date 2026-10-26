#include <stdio.h>
int sumnatural(int num) {
        return num ? num + sumnatural(num-1):0;
}

int main() {

    int num = 10;
    int result = 0;
    for (int i = 1; i <= num; ++i) {
        result+=i;
    }
    printf("%d\n",result);

    printf("%d\n",sumnatural(100));

    return 0;
}