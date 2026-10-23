
#include <stdio.h>
#include <string.h>
#include <limits.h>

    // 3. Hard
    // Write a C program to find the longest substring without repeating characters in a given string.
    //test cases
    //abcabcbb
    //abc
    //bbbbb
    //b
    //pwwkew
    //wke
    //abcdef
    //abcdef



int main()
{
    // Static input string: change this value to test another string.
    char input_string[] = "abcdabcdbb";

    int string_length = strlen(input_string);

    // Store the last position of each character.
    // -1 means the character has not appeared yet.
    int last_seen_index[UCHAR_MAX + 1];

    for (int i = 0; i <= UCHAR_MAX; i++)
    {
        last_seen_index[i] = -1;
    }

    // Beginning of the current substring without repetitions.
    int window_start = 0;

    // Information about the longest substring found.
    int longest_substring_start = 0;
    int longest_substring_length = 0;

    // Examine the string from left to right.
    for (int current_index = 0;
         current_index < string_length;
         current_index++)
    {
        unsigned char current_character =
            (unsigned char)input_string[current_index];

        // If this character repeats inside the current window,
        // move the beginning past its previous occurrence.
        if (last_seen_index[current_character] >= window_start)
        {
            window_start = last_seen_index[current_character] + 1;
        }

        // Update the most recent position of this character.
        last_seen_index[current_character] = current_index;

        // Calculate the length of the current valid substring.
        int current_length = current_index - window_start + 1;

        // Save it if it is longer than the previous best.
        if (current_length > longest_substring_length)
        {
            longest_substring_length = current_length;
            longest_substring_start = window_start;
        }
    }

    // Print the longest substring and its length.
    printf("String: %s\n", input_string);

    printf("Longest substring: ");

    for (int i = 0; i < longest_substring_length; i++)
    {
        printf("%c", input_string[longest_substring_start + i]);
    }

    printf("\nLength: %d\n", longest_substring_length);

    return 0;
}
