#include <stdio.h>
#include "student.h"
#include "utils.h"
#include <string.h>

void add_student(Student *students, int *count)
{
    if (*count >= MAX_STUDENTS)
    {
        printf("Cannot add more students. Database full.\n");
        return;
    }

    printf("Enter student ID: ");
    students[*count].id = get_int_input();
    clear_buffer(); // Clear input buffer
    printf("Enter student name: ");
    fgets(students[*count].name, 50, stdin);
    students[*count].name[strcspn(students[*count].name, "\n")] = '\0'; // Remove newline character
    printf("Enter student age: ");
    students[*count].age = get_int_input();
    printf("Enter student grade: ");
    fgets(students[*count].grade, 5, stdin);
    students[*count].grade[strcspn(students[*count].grade, "\n")] = '\0'; // Remove newline character

    (*count)++;
    printf("Student added successfully.\n");
}

void delete_student(Student *students, int *count, int id)
{
    int i, found = 0;

    for (i = 0; i < *count; i++)
    {
        if (students[i].id == id)
        {
            found = 1;
            break;
        }
    }

    if (found)
    {
        for (; i < *count - 1; i++)
        {
            students[i] = students[i + 1];
        }
        (*count)--;
        printf("Student deleted successfully.\n");
    }
    else
    {
        printf("Student with ID %d not found.\n", id);
    }
}

void search_student(Student *students, int count, int id)
{
    int i, found = 0;

    for (i = 0; i < count; i++)
    {
        if (students[i].id == id)
        {
            found = 1;
            printf("Student found:\n");
            printf("ID: %d\nName: %s\nAge: %d\nGrade: %s\n",
                   students[i].id, students[i].name, students[i].age, students[i].grade);
            break;
        }
    }

    if (!found)
    {
        printf("Student with ID %d not found.\n", id);
    }
}

void list_students(Student *students, int count)
{
    if (count == 0)
    {
        printf("No students in the database.\n");
        return;
    }

    printf("List of students:\n");
    for (int i = 0; i < count; i++)
    {
        printf("ID: %d\nName: %s\nAge: %d\nGrade: %s\n\n",
               students[i].id, students[i].name, students[i].age, students[i].grade);
    }
}
