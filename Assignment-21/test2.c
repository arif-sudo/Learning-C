// get employee count from user
// loop to assign id to employees
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Employee
{
    int id;
    char firstName[30];
    char lastName[30];
    char title[30];
    int SSN_4;
};
typedef struct Employee Employee;
struct Employees
{
    Employee *empoyeeArr;
    int count;
};
typedef struct Employees Employees;
void assignValue(Employees *e, int count);
void printValue(Employees e, int count);

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the number of Employees you want to declare: ");
    scanf("%d", &n);
    Employees employees;
    employees.empoyeeArr = NULL;

    employees.empoyeeArr = realloc(employees.empoyeeArr, n * sizeof(Employee));
    if (employees.empoyeeArr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        assignValue(&employees, i);
        puts("");
    }
    for (int i = 0; i < n; i++)
    {
        printValue(employees, i);
        puts("");
    }
    // Free dynamically allocated memory
    free(employees.empoyeeArr);
    return 0;
}

void assignValue(Employees *employees, int i)
{
    // Declaring int i to 0 because array indexing is C starts from 0
    employees->empoyeeArr[i].id = i + 1;

    printf("Enter employee's First Name: ");
    scanf("%5s", &employees->empoyeeArr[i].firstName);

    printf("Enter employee's Last Name: ");
    scanf("%s", &employees->empoyeeArr[i].lastName);

    printf("Enter employee's Title: ");
    scanf("%s", &employees->empoyeeArr[i].title);

    printf("Enter employee's SSN digits: ");
    scanf("%d", &employees->empoyeeArr[i].SSN_4);
}

void printValue(Employees employees, int i)
{
    printf("ID: %d\n", employees.empoyeeArr[i].id);
    printf("First Name: %s\n", employees.empoyeeArr[i].firstName);
    printf("Last Name: %s\n", employees.empoyeeArr[i].lastName);
    printf("Title: %s\n", employees.empoyeeArr[i].title);
    printf("SSN digits: %d\n", employees.empoyeeArr[i].SSN_4);
}
