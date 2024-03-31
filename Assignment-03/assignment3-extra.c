#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int main(void)
{
  // initialize vars
  char *first;
  char *last;

  // prompt user to input first and last name and use scanf() to store those to the initiliazed vars
  printf("Enter your last name: ");
  scanf("%s", &first);

  printf("Enter your last name: ");
  scanf("%s", &last);

  // print the welcome message!
  printf("Hello %ms %ms!\n", first, last);

  free(first);
  free(last);
}
