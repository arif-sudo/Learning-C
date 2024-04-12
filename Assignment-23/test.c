#include <stdio.h>

struct Test
{
    float f;
};

int main(int argc, char const *argv[])
{
    struct Test *ptr;
    struct Test test;
    ptr = &test;

    test.f = 3.14;
    printf("1) %.2f\n", test.f);

    (*ptr).f = 6.28;
    printf("2) %.2f\n", test.f);

    ptr->f = 9.42;
    printf("3) %.2f", test.f);

    return 0;
}
