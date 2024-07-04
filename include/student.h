#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 100 // Define the maximum number of students

typedef struct
{
    int id;
    char name[50];
    int age;
    char grade[5];
} Student;

void add_student(Student *students, int *count);
void delete_student(Student *students, int *count, int id);
void search_student(Student *students, int count, int id);
void list_students(Student *students, int count);

#endif // STUDENT_H
