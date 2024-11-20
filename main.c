#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

int main() {
    Student* head = NULL;
    int choice;

    do {
        printf("Menu:\n");
        printf("1. Add a student\n");
        printf("2. Delete students by last name\n");
        printf("3. Print list forward\n");
        printf("4. Print list backward\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // clear newline

        switch (choice) {
            case 1:
                appendStudent(&head, createStudent());
                break;
            case 2: {
                char lastName[50];
                printf("Enter last name to delete: ");
                fgets(lastName, 50, stdin);
                lastName[strcspn(lastName, "\n")] = '\0';
                deleteStudentsByLastName(&head, lastName);
                break;
            }
            case 3:
                printListForward(head);
                break;
            case 4:
                if (head) {
                    Student* tail = head;
                    while (tail->next != NULL) {
                        tail = tail->next;
                    }
                    printListBackward(tail);
                }
                break;
            case 5:
                freeList(head);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}