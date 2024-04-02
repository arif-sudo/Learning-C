#include <stdio.h>
#include <string.h>

struct student
{
    char *name;
    int age;
    float gpa;
} s1;

int main(int argc, char const *argv[])
{
    s1.name = "Hello";  //you cannot assign a string literal directly to an array in C (char name[20] previously). Arrays are not assignable in C
    //strcpy(s1.name, "W.W");
    s1.age = 50;
    s1.gpa = 96;
    struct student s2 = {"Cemil", 20, 88.25f}, s3;
    s3 = s1;
    printf("Greetinigs %s \n%d years old \n%.2f overall GPA\n", s1.name, s1.age, s1.gpa);
    printf("Greetinigs %s \n%d years old \n%.2f overall GPA\n", s2.name, s2.age, s2.gpa);
    printf("Greetinigs %s \n%d years old \n%.2f overall GPA\n", s3.name, s3.age, s3.gpa);


    return 0;
}
