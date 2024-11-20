#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

// Create a student
Student* createStudent() {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (!newStudent) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newStudent->lastName = (char*)malloc(50);
    newStudent->firstName = (char*)malloc(50);
    newStudent->year = (char*)malloc(20);

    printf("Enter the student's last name: ");
    fgets(newStudent->lastName, 50, stdin);
    newStudent->lastName[strcspn(newStudent->lastName, "\n")] = '\0';

    printf("Enter the student's first name: ");
    fgets(newStudent->firstName, 50, stdin);
    newStudent->firstName[strcspn(newStudent->firstName, "\n")] = '\0';

    printf("Enter the student's ID number: ");
    scanf("%ld", &newStudent->id);

    printf("Enter the student's year (freshman, sophomore, etc.): ");
    getchar();  // clear newline
    fgets(newStudent->year, 20, stdin);
    newStudent->year[strcspn(newStudent->year, "\n")] = '\0';

    printf("Enter the student's expected graduation year: ");
    scanf("%d", &newStudent->gradYear);
    getchar();  // clear newline

    newStudent->next = NULL;
    newStudent->prev = NULL;

    return newStudent;
}

// Append to the list
void appendStudent(Student** head, Student* newStudent) {
    if (*head == NULL) {
        *head = newStudent;
        return;
    }

    Student* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newStudent;
    newStudent->prev = temp;
}

// Print the list forward
void printListForward(Student* head) {
    Student* temp = head;
    while (temp != NULL) {
        printf("%s, %s, ID: %ld, Year: %s, Graduation: %d\n", 
               temp->lastName, temp->firstName, temp->id, temp->year, temp->gradYear);
        temp = temp->next;
    }
}

// Print the list backward
void printListBackward(Student* tail) {
    Student* temp = tail;
    while (temp != NULL) {
        printf("%s, %s, ID: %ld, Year: %s, Graduation: %d\n", 
               temp->lastName, temp->firstName, temp->id, temp->year, temp->gradYear);
        temp = temp->prev;
    }
}

// Delete by last name
void deleteStudentsByLastName(Student** head, const char* lastName) {
    Student* temp = *head;
    while (temp != NULL) {
        if (strcmp(temp->lastName, lastName) == 0) {
            if (temp->prev) {
                temp->prev->next = temp->next;
            } else {
                *head = temp->next;
            }

            if (temp->next) {
                temp->next->prev = temp->prev;
            }

            Student* toDelete = temp;
            temp = temp->next;
            freeStudent(toDelete);
        } else {
            temp = temp->next;
        }
    }
}

// Free memory student
void freeStudent(Student* student) {
    if (student) {
        free(student->lastName);
        free(student->firstName);
        free(student->year);
        free(student);
    }
}

// Free memory for the entire list :>
void freeList(Student* head) {
    Student* temp = head;
    while (temp != NULL) {
        Student* next = temp->next;
        freeStudent(temp);
        temp = next;
    }
}
