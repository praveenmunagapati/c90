// #include <stdint.h>
// #include <stdio.h>
// #include <stdlib.h>
//
//
// int main() {
//     /* d) A Fibonacci sequence is defined as follows:
//        the first and second terms in the sequence are 0 and 1.
//        Subsequent terms are found by adding the preceding two terms in the sequence.
//        write a C program to generate the first n terms of the sequence.
//     */
//
//     unsigned long long sum = 0;
//     unsigned long long n = 100;
//     unsigned long long first = 0;
//     unsigned long long second = 1;
//     printf("%llu\n",first);
//     printf("%llu\n",second);
//
//     for (int i = 1;i<=n;i++) {
//
//         if (second > UINT64_MAX - first)
//         {
//             printf("reached max allowed space %llu \n ",ULONG_LONG_MAX);
//             break;
//             /*
//              *first 4660046610375530309 + second 7540113804746346429 =  sum 12200160415121876738
//              * first 7540113804746346429
//              * second 12200160415121876738
//              * second > UINT64_MAX - first
//              *         18446744073709551615 - 7540113804746346429 = 10906630268963205186
//              *         12200160415121876738 > 10906630268963205186 (low space)
//              *
//              *
//              *         That “remaining space” way of thinking is the key.
//              *         Once you see it that way, unsigned overflow checks become much easier to remember.
//              */
//         }
//         sum = first + second;
//         printf("%d first %llu + second %llu =  sum %llu\n",i,first,second,sum);
//         first = second;
//         second = sum;
//
//     }
//     if (__builtin_add_overflow(first, second, &sum))
//     {
//         printf("Overflow\n");
//     }
//
//     return 0;
// }
// #include <stdio.h>
//
// void print128(unsigned __int128 n)
// {
//     if (n == 0)
//     {
//         printf("0");
//         return;
//     }
//
//     char digits[40];
//     int i = 0;
//
//     while (n > 0)
//     {
//         digits[i++] = '0' + n % 10;
//         n /= 10;
//     }
//
//     while (i--)
//         putchar(digits[i]);
// }
//
// int main()
// {
//     setbuf(stdout,NULL);
//     unsigned __int128 first = 0;
//     unsigned __int128 second = 1;
//     unsigned __int128 sum;
//
//     int n = 1000;
//
//     for (int i = 0; i < n; i++)
//     {
//                 printf("%d\t",i);
//         print128(first);
//         printf("\n");
//
//         sum = first + second;
//
//         if (sum < first)
//         {
//             printf("128-bit overflow reached\n");
//             break;
//         }
//
//         first = second;
//         second = sum;
//     }
//
//     return 0;
// }

#include <stdio.h>

#define SIZE 10000

typedef struct
{
    int digit[SIZE];
    int length;
} BigInt;


void set(BigInt *x, int value)
{
    x->length = 0;

    if (value == 0)
    {
        x->digit[0] = 0;
        x->length = 1;
        return;
    }

    while (value > 0)
    {
        x->digit[x->length++] = value % 10;
        value /= 10;
    }
}


void add(BigInt *a, BigInt *b, BigInt *result)
{
    int carry = 0;
    int i;

    for (i = 0; i < a->length || i < b->length || carry; i++)
    {
        int sum = carry;

        if (i < a->length)
            sum += a->digit[i];

        if (i < b->length)
            sum += b->digit[i];

        result->digit[i] = sum % 10;
        carry = sum / 10;
    }

    result->length = i;
}


void print(BigInt *x)
{
    for (int i = x->length - 1; i >= 0; i--)
        printf("%d", x->digit[i]);

    printf("\n");
}


int main()
{
    BigInt first;
    BigInt second;
    BigInt sum;

    set(&first, 0);
    set(&second, 1);

    int n = 10000;

    for (int i = 0; i < n; i++)
    {
        printf("%d\t",i);;

        print(&first);

        add(&first, &second, &sum);

        first = second;
        second = sum;
    }

    return 0;
}