// define a  structure named Student(roll_no, name, branch and batch_no) and access the structure members using Pointer

#include <stdio.h>

struct Student
{
    int roll_no;
    char name[50];
    char branch[30];
    int batch_no;
};

void main()
{
    struct Student s;
    struct Student *ptr = &s;

    printf("Enter Roll Number: ");
    scanf("%d", &ptr->roll_no);

    printf("Enter Name: ");
    scanf("%s", ptr->name);

    printf("Enter Branch: ");
    scanf("%s", ptr->branch);

    printf("Enter Batch Number: ");
    scanf("%d", &ptr->batch_no);

    printf("\nStudent Details\n");
    printf("Roll No : %d\n", ptr->roll_no);
    printf("Name : %s\n", ptr->name);
    printf("Branch : %s\n", ptr->branch);
    printf("Batch No : %d\n", ptr->batch_no);
}
