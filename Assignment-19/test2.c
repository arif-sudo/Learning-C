// Here's an example of how you might inadvertently overwrite memory beyond what was allocated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *ptr = malloc(10 * sizeof(char)); // Allocate memory for 5 characters

    if (ptr == NULL) {
        puts("Memory allocation failed");
        return 1;
    }
    //puts("Hello?");
    strcpy(ptr, "Hello, World!"); // This will cause buffer overflow

    printf("String stored in ptr: %s\n", ptr);
    // Not printing values of ptr if allocation character is too low ( 5 for examples)
    free(ptr);

    return 0;
}
