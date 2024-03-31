#include <stdio.h>

void hello(void)
{
    char array[] = {72, 101, 108, 108, 111, 44, 32, 87, 111, 114, 108, 100, 33};

    printf("%c", (char)72);
    printf("%c", (char)101);
    printf("%c", (char)108);
    printf("%c", (char)108);
    printf("%c\n", (char)111);

    printf("%s\n", array);
    puts(array);

    fputs("Geeks ", stdout);
    fputs("for ", stdout);
    fputs("Geeks\n", stdout);
}
// puts() is a function defined in header <stdio.h> that prints strings character by character until the NULL character is encountered.
// puts() function is used to write a string to the console and it automatically adds a new line character '\n' at the end.
// returns a non-negative value if the output is successful?, or End-of-File if an error occurs

// % is intentionally put here to show the unexpected behaviour when %s is used in printf
// printf("Geek%sforGeek%s");
// getchar();
int main(void)
{
    hello();
    return 0;
}