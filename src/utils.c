#include <stdio.h>
#include "utils.h"

void clear_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int get_int_input()
{
    int input;
    while (scanf("%d", &input) != 1)
    {
        clear_buffer();
        printf("Invalid input. Please enter a number: ");
    }
    clear_buffer(); // Clear any remaining characters in input buffer
    return input;
}
