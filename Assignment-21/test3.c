#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Employee struct
struct Employee {
    char name[50]; // Assuming a maximum length for the name
    char title[50]; // Assuming a maximum length for the title
    int id;
};

// Define the Employees struct
struct Employees {
    struct Employee *employees; // Pointer to an array of Employee structs
    int count; // Number of employees in the array
};

// Function to add an employee to the Employees struct
void addEmployee(struct Employees *employees) {
    // Dynamically reallocate memory to increase the size of the employees array
    employees->employees = malloc(employees->employees, (employees->count + 1) * sizeof(struct Employee));
    if (employees->employees == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Prompt user for employee details
    printf("Enter employee name: ");
    scanf("%s", employees->employees[employees->count].name);
    printf("Enter employee title: ");
    scanf("%s", employees->employees[employees->count].title);
    printf("Enter employee ID: ");
    scanf("%d", &employees->employees[employees->count].id);

    // Increment the count of employees
    employees->count++;
}

int main() {
    struct Employees employees;
    employees.employees = NULL; // Initialize the employees array to NULL
    employees.count = 0; // Initialize the count of employees to 0

    char choice;
    do {
        addEmployee(&employees); // Add an employee
        printf("Do you want to add another employee? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    // Print the list of employees
    printf("List of employees:\n");
    for (int i = 0; i < employees.count; i++) {
        printf("Employee %d:\n", i+1);
        printf("Name: %s\n", employees.employees[i].name);
        printf("Title: %s\n", employees.employees[i].title);
        printf("ID: %d\n", employees.employees[i].id);
    }

    // Free dynamically allocated memory
    free(employees.employees);

    return 0;
}
