#include <stdio.h>
#include "student.h"
#include "utils.h"

#define MAX_STUDENTS 100

int main()
{
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    printf("Welcome to Student Management System\n");

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Search Student\n");
        printf("4. List Students\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        choice = get_int_input();

        switch (choice)
        {
        case 1:
            add_student(students, &count);
            break;
        case 2:
        {
            int id;
            printf("Enter student ID to delete: ");
            id = get_int_input();
            delete_student(students, &count, id);
            break;
        }
        case 3:
        {
            int id;
            printf("Enter student ID to search: ");
            id = get_int_input();
            search_student(students, count, id);
            break;
        }
        case 4:
            list_students(students, count);
            break;
        case 5:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    }

    return 0;
}
