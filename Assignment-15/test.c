#include <stdio.h>

int main()
{
    int var = 10;
    int *pointer = &var;

    printf("*ptr - %d\n", *pointer);
    printf("variable - %d\n", var);
    printf("ptr - %p\n", pointer);
    printf("&variable - %p\n\n", &var);

    printf("The value of int variable is: %d\n", var);
    printf("The value of the pointer to the int variable is: %d\n", pointer);
    printf("The memory address of the int variable is: %d\n", &var);
    printf("The value held at the memory location that the pointer is pointing to is: %d\n", *pointer);

    return 0;
}