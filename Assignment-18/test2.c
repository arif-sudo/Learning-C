#include <stdio.h>

void hello(void)
{
	char array[] = {72, 101, 108, 108, 111, 44, 32, 87, 111, 114, 108, 100, 33, '\0'};
    // '\0' - NULL character or NULL terminator
    //It has a value of 0 in ASCII encoding and is used to terminate strings in C-style strings
	puts(array);
	printf("%s", array);
}

int main(void) 
{
	hello();
}