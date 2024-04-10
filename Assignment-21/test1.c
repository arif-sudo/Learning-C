#include <stdio.h>
#include <stdlib.h>

struct Employee
{
    int id;
    char firstName[30]; // char *firstName; Issue[1]
    char lastName[30];  // char *lastName;
    char title[30];     // char *title;
    int SSN_4;
};
// Define a new data type 'Employee' using typedef
typedef struct Employee Employee;

void getEmployee(Employee *e);// Pass Employee by reference Issue[2]
void printEmployee(Employee e);

struct Employees
{
    Employee employee_1;
    Employee employee_2;
};
typedef struct Employees Employees;

int main(int argc, char const *argv[])
{
    Employees employees;

    printf("Enter first employees credentials\n");
    getEmployee(&employees.employee_1);  // Pass the address of employees.employee_1 Issue[2]

    printf("\nEnter second employees credentials\n");
    getEmployee(&employees.employee_2);

    printEmployee(employees.employee_1);
    printEmployee(employees.employee_2);

    return 0;
}

void getEmployee(Employee *e)
{
    printf("Enter employee's ID: ");
    //scanf("%d", &e.id); // error: 'e' is a pointer; did you mean to use '->'?
    scanf("%d", &e->id); 

    printf("Enter employee's First Name: ");
    scanf("%s", &e->firstName);

    printf("Enter employee's Last Name: ");
    scanf("%s", &e->lastName);

    printf("Enter employee's Title: ");
    scanf("%s", &e->title);

    printf("Enter employee's SSN digits: ");
    scanf("%d", &e->SSN_4);
}
void printEmployee(Employee e)
{
    printf("Employee id: %d \nN.S: %s %s \nTitle: %s \nSSN_4: %d\n", e.id, e.firstName, e.lastName, e.title, e.SSN_4);
}
/*
 * Issue 1
 * Previous code lies in the usage of scanf for string inputs (char* fields like firstName, lastName, and title).
 * scanf with %s format specifier reads characters until it encounters whitespace.
 * It's not suitable for reading strings with spaces because it stops reading at the first space.
 * To fix this issue, you may use fgets or change declaration of string characters.
 */

/* Issue 2
 * Previous code stems from passing the Employee structure to the getEmployee function by value.  
 * To resolve this issue, you should pass the Employee structure by reference (using pointers).
*/