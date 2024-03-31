#include <stdio.h>

int main(int argc, char *argv[])
{

    int m = 5;
    int *p = &m;
    int **pp = &p;

    (*p)++;
    (**pp)++;
    printf("Value of integer m is %d\n", m);
    printf("Value which pointer *p points at is %d\n\n", *p);

    printf("Value of pointer p is %p\n", p);
    printf("Memory address of m: %p\nWhich means pointer p stores memory address of variable m\n", &m);
    printf("Memory address of pointer p: %p\n\n", &p);

    printf("Value which pointer *pp points at is %p\n", *pp);
    printf("Value which pointer **pp points at is: %d\n\n", **pp);

    printf("Memory address of pointer p: %p\n", &p);
    printf("Value of pointer pp: %p\n", pp);
    printf("Memory address of pointer pp: %p\n\n", &pp);

    //
    int n = 90;
    int* pointer = &n;
    printf("Value of pointer variable is %d\n", *pointer);

    return 0;
}