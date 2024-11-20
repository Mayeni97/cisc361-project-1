#ifndef STUDENT_H
#define STUDENT_H

typedef struct Student {
    char* lastName;
    char* firstName;
    long id;
    char* year;
    int gradYear;
    struct Student* next;
    struct Student* prev;
} Student;

// Function prototypes
Student* createStudent();
void appendStudent(Student** head, Student* newStudent);
void printListForward(Student* head);
void printListBackward(Student* tail);
void deleteStudentsByLastName(Student** head, const char* lastName);
void freeStudent(Student* student);
void freeList(Student* head);

#endif // STUDENT_H
