#include <stdio.h>
#include <string.h>

int main() {

    char str[] = "Hello"; // Compiler appends '\0' automatically

    printf("Length of str: %d\n", strlen(str)); // Outputs: 5

    return 0;

}