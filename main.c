#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
    /* d) A Fibonacci sequence is defined as follows:
       the first and second terms in the sequence are 0 and 1.
       Subsequent terms are found by adding the preceding two terms in the sequence.
       write a C program to generate the first n terms of the sequence.
    */

    unsigned long long sum = 0;
    unsigned long long n = 100;
    unsigned long long first = 0;
    unsigned long long second = 1;
    printf("%llu\n",first);
    printf("%llu\n",second);

    for (int i = 1;i<=n;i++) {

        if (second > UINT64_MAX - first)
        {
            printf("reached max allowed space %llu \n ",ULONG_LONG_MAX);
            break;
            /*
             *first 4660046610375530309 + second 7540113804746346429 =  sum 12200160415121876738
             * first 7540113804746346429
             * second 12200160415121876738
             * second > UINT64_MAX - first
             *         18446744073709551615 - 7540113804746346429 = 10906630268963205186
             *         12200160415121876738 > 10906630268963205186 (low space)
             *
             *
             *         That “remaining space” way of thinking is the key.
             *         Once you see it that way, unsigned overflow checks become much easier to remember.
             */
        }
        sum = first + second;
        printf("%d first %llu + second %llu =  sum %llu\n",i,first,second,sum);
        first = second;
        second = sum;

    }

    return 0;
}
