#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    // char buffer[50];
    // sprintf(buffer, "Size of char is %zu", sizeof(char));
    // puts(buffer);
    //  Here, %zu is the format specifier for size_t type, which is the return type of sizeof.
    //  This code will print the size of char.

    printf("Size of char is: %d byte(s)\n", sizeof(char));

    // Allocating memory for the char strings
    char *charStringA = malloc(10 * sizeof(char));
    char *charStringB = malloc(17 * sizeof(char));

    if (charStringA == NULL || charStringB == NULL)
    {
        puts("Memory allocation failed");
        return 1;
    }else {
        puts("Memory allocated successfully");
    }

    sprintf(charStringA, "Size of charStringA is %zu", sizeof(charStringA));
    puts(charStringA); // 4
    sprintf(charStringB, "Size of charStringB is %zu", sizeof(charStringB));
    puts(charStringB); // 4

    /*
     * When you use sizeof(charStringA) and sizeof(charStringB), you're actually getting the size of pointers,
     * not the size of the allocated memory blocks.
     * Therefore, the output will likely be the size of a pointer (usually 4 or 8 bytes depending on the system),
     * not the size of the allocated memory.
     */
    strcpy(charStringA, "Hello ");
    strcpy(charStringB, "World!");

    printf("%s%s\n", charStringA, charStringB);
    puts(charStringA);
    puts(charStringB);

    free(charStringA);
    free(charStringB);
    return 0;
}
