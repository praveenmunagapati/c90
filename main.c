#include <stdio.h>
#include <string.h>
/*
    a) Write a C program that uses functions to perform the following operations:
        I. To insert a sub-string into a given main string from a given position.
        II. To delete n Characters from a given position in a given string.
*/

int main() {
    char string[20] = "hello";
    printf("%s\n",string);
    //I. To insert a sub-string into a given main string from a given position.
    int pos = 3;
    char substring[20] = "world";
    char newstring[40];
    //lets copy up to pos 2
    for (int i = 0; i < pos; ++i) {
        newstring[i]  = string[i];
    }
    printf("%s\n",newstring);
    //now copy substring
    for (int i = 0; i < strlen(substring); ++i) {
        newstring[pos+i]  = substring[i];
    }
    printf("%s\n",newstring);
    //now append remaining  main string
    for (int i = 0; i < strlen(string) - pos + 1; ++i) {
        newstring[pos + strlen(substring) + i]  = string[pos + i];
    }
    printf("%s\n",newstring);
    



    return 0;
}