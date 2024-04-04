#include <stdio.h>
#define geeks(T) _Generic((T), \ 
        char *: "String", \ 
        int: "Integer", \ 
        long: "Long Integer", \ 
        default: "Others")

void illustrate();

struct data
{
    char first[20];
    char last[20];
    int employee_id; // 4
    int last_4_SSN;  // 4
    char title[20];
};
int main()
{
    illustrate();
    struct data employee;
    struct data *ptr_employee = &employee;

    printf("Size of 'employee': %zu bytes\n", sizeof(employee));
    printf("Size of 'ptr_employee': %zu bytes\n", sizeof(*ptr_employee)); // Dereference the pointer

    printf("Type of 'employee': %s\n", _Generic(employee, struct data: "struct data"));
    printf("Type of 'ptr_employee': %s\n", _Generic(ptr_employee, struct data *: "struct data pointer"));

    return 0;
}
void illustrate()
{
    // _Generic keyword acts as a switch that chooses operation based on data type of argument.
    printf("1) %d\n", _Generic(1.1f, float: 1, double: 2, long: 3, long double: 4, default: 0));

    printf("2) %d\n", _Generic(1.2, float: 1, double: 2, long: 3, long double: 4, default: 0));

    printf("3) %d\n", _Generic(1L, float: 1, double: 2, long: 3, long double: 4, default: 0));

    printf("4) %d\n", _Generic(1.0L, float: 1, double: 2, long: 3, long double: 4, default: 0));

    printf("5) %d\n", _Generic(1.0L, float: 1, double: 2, long: 3, default: 0));

    printf("6) %d\n", _Generic('A', float: 1, double: 2, long: 3, long double: 4, int: 5, char: 6, default: 0));

    printf("7) %d\n", _Generic((char)'B', float: 1, double: 2, long: 3, long double: 4, int: 5, char: 6, default: 0));

    printf("7) %d\n", _Generic("C", float: 1, double: 2, long: 3, long double: 4, int: 5, char: 6, char *: 7, default: 0));
}