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

// #include <stdio.h>
//
// #define SIZE 10000
//
// typedef struct
// {
//     int digit[SIZE];
//     int length;
// } BigInt;
//
//
// void set(BigInt *x, int value)
// {
//     x->length = 0;
//
//     if (value == 0)
//     {
//         x->digit[0] = 0;
//         x->length = 1;
//         return;
//     }
//
//     while (value > 0)
//     {
//         x->digit[x->length++] = value % 10;
//         value /= 10;
//     }
// }
//
//
// void add(BigInt *a, BigInt *b, BigInt *result)
// {
//     int carry = 0;
//     int i;
//
//     for (i = 0; i < a->length || i < b->length || carry; i++)
//     {
//         int sum = carry;
//
//         if (i < a->length)
//             sum += a->digit[i];
//
//         if (i < b->length)
//             sum += b->digit[i];
//
//         result->digit[i] = sum % 10;
//         carry = sum / 10;
//     }
//
//     result->length = i;
// }
//
//
// void print(BigInt *x)
// {
//     for (int i = x->length - 1; i >= 0; i--)
//         printf("%d", x->digit[i]);
//
//     printf("\n");
// }
//
//
// int main()
// {
//     BigInt first;
//     BigInt second;
//     BigInt sum;
//
//     set(&first, 0);
//     set(&second, 1);
//
//     int n = 10000;
//
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d\t",i);;
//
//         print(&first);
//
//         add(&first, &second, &sum);
//
//         first = second;
//         second = sum;
//     }
//
//     return 0;
// }
//
//
// #include <stdio.h>
// //d) Write a program for display values reverse order from an array using a pointer.
//
// int mainp() {
//     int array[10] = {10,55,37,49,54,26,75,87,19,101};
//     int *parray = &array[9];
//     for(int i = 0;i<10;i++){
//         printf("%d\t",*(parray-i));
//     }
//     printf("Try clicking the Run button.");
//     return 0;
// }

// #include <stdio.h>
//
// #define SIZE 100
// #define BASE 100000000
//
// typedef struct
// {
//     unsigned int digit[SIZE];
//     int length;
// } BigInt;
//
//
// void set(BigInt *x, unsigned int value)
// {
//     x->length = 0;
//
//     while (value > 0)
//     {
//         x->digit[x->length++] = value % BASE;
//         value /= BASE;
//     }
//
//     if (x->length == 0)
//         x->length = 1;
// }
// int add(BigInt *a, BigInt *b, BigInt *result)
// {
//     unsigned long long sum;
//     unsigned long long carry = 0;
//
//     int i;
//
//     for (i = 0; i < a->length || i < b->length || carry; i++)
//     {
//         if (i >= SIZE)
//         {
//             return 0;       // BigInt overflow
//         }
//
//         sum = carry;
//
//         if (i < a->length)
//             sum += a->digit[i];
//
//         if (i < b->length)
//             sum += b->digit[i];
//
//         result->digit[i] = sum % BASE;
//
//         carry = sum / BASE;
//     }
//
//     result->length = i;
//
//     return 1;               // success
// }
//
// void addunmodified(BigInt *a, BigInt *b, BigInt *result)
// {
//     unsigned long long sum;
//     unsigned long long carry = 0;
//
//     int i;
//
//     for (i = 0; i < a->length || i < b->length || carry; i++)
//     {
//         sum = carry;
//
//         if (i < a->length)
//             sum += a->digit[i];
//
//         if (i < b->length)
//             sum += b->digit[i];
//
//         result->digit[i] = sum % BASE;
//
//         carry = sum / BASE;
//     }
//
//     result->length = i;
// }
//
//
// void print(BigInt *x)
// {
//     int i;
//
//     printf("%u", x->digit[x->length - 1]);
//
//     for (i = x->length - 2; i >= 0; i--)
//         printf("%08u", x->digit[i]);
//
//     printf("\n");
// }
//
//
// int main()
// {
//     BigInt first;
//     BigInt second;
//     BigInt sum;
//
//     set(&first, 0);
//     set(&second, 1);
//
//     int n = 10000;
//
//     for (int i = 0; i < n; i++)
//     {   printf("%d\t",i);;
//         print(&first);
//
//         if (!add(&first, &second, &sum))
//         {
//             printf("BigInt overflow: capacity reached\n");
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
#include <stdlib.h>

#define BASE 100000000


typedef struct
{
    unsigned int *digit;
    size_t length;
    size_t capacity;
} BigInt;


void init(BigInt *x)
{
    x->capacity = 4;

    x->digit = malloc(
        x->capacity * sizeof(unsigned int)
    );

    x->length = 1;
    x->digit[0] = 0;
}


void destroy(BigInt *x)
{
    free(x->digit);

    x->digit = NULL;
    x->length = 0;
    x->capacity = 0;
}


void reserve(BigInt *x, size_t required)
{
    if (required <= x->capacity)
        return;

    while (x->capacity < required)
        x->capacity *= 2;

    x->digit = realloc(
        x->digit,
        x->capacity * sizeof(unsigned int)
    );
}


void set(BigInt *x, unsigned int value)
{
    x->length = 0;

    while (value > 0)
    {
        x->digit[x->length++] = value % BASE;
        value /= BASE;
    }

    if (x->length == 0)
    {
        x->length = 1;
        x->digit[0] = 0;
    }
}


void add(BigInt *a, BigInt *b, BigInt *result)
{
    unsigned long long sum;
    unsigned long long carry = 0;

    size_t max;

    max = a->length > b->length
        ? a->length
        : b->length;

    reserve(result, max + 1);

    size_t i;

    for (i = 0; i < max || carry; i++)
    {
        sum = carry;

        if (i < a->length)
            sum += a->digit[i];

        if (i < b->length)
            sum += b->digit[i];

        result->digit[i] = sum % BASE;

        carry = sum / BASE;
    }

    result->length = i;
}


void print(BigInt *x)
{
    int i;

    printf("%u", x->digit[x->length - 1]);

    for (i = x->length - 2; i >= 0; i--)
        printf("%08u", x->digit[i]);

    printf("\n");
}


int main()
{
    BigInt first;
    BigInt second;
    BigInt sum;

    init(&first);
    init(&second);
    init(&sum);

    set(&first, 0);
    set(&second, 1);

    int n = 10000;

    for (int i = 0; i < n; i++)
    {
        printf("%d\t",i);
        print(&first);

        add(&first, &second, &sum);

        /*
             first = second
             second = sum
        */

        BigInt temp;

        temp = first;
        first = second;
        second = sum;
        sum = temp;
    }

    destroy(&first);
    destroy(&second);
    destroy(&sum);

    return 0;
}