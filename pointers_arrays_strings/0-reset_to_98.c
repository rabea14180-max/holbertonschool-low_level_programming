#include <stdio.h>
#include "main.h"

void reset_to_98(int *n)
{
    *n = 98;  // Update the value at the address pointed to by n
}

int main()
{
    int number = 5;
    printf("Before: %d\n", number);

    reset_to_98(&number);  // Pass the address of number

    printf("After: %d\n", number);
    return 0;
}
