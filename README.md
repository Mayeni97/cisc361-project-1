
# CISC361 Project 1

This project is uses C and doubly linked list to manage student records. It allows users to:

- Add a new student.
- Delete students by last name.
- Print the list of students in forward or backward order.
- Free the entire list and exit the program.

## Features

1. **Add a student**: Appends a new student to the doubly linked list, capturing details like first name, last name, ID, year, and graduation year.
2. **Delete students by last name**: Deletes all students from the list who match a specified last name.
3. **Print list forward**: Prints the list of students from the first to the last student.
4. **Print list backward**: Prints the list of students from the last to the first student.
5. **Exit**: Frees all dynamically allocated memory and terminates the program.

## Structure Overview

The `Student` structure is defined in the `student.h` header file as follows:

```c
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
```

### Functions

- **`Student* createStudent()`**: Dynamically allocates memory for a student and prompts the user for input.
- **`void appendStudent(Student** head, Student* newStudent)`**: Appends a student to the end of the list.
- **`void printListForward(Student* head)`**: Prints the list of students in forward order.
- **`void printListBackward(Student* tail)`**: Prints the list of students in reverse order.
- **`void deleteStudentsByLastName(Student** head, const char* lastName)`**: Deletes all students matching the given last name.
- **`void freeStudent(Student* student)`**: Frees the memory for a single student.
- **`void freeList(Student* head)`**: Frees the entire student list.

## Prerequisites

- **C Compiler (e.g., GCC)**
- **Makefile (optional for ease of use)**

## Compilation and Execution

You can use the provided `Makefile` to compile and clean the project.

### Using Makefile

1. To compile the program:

    ```bash
    make slist
    ```

2. To clean up the generated files:

    ```bash
    make clean
    ```

### Direct Compilation (without Makefile)

If you prefer to compile directly without the `Makefile`, run the following command:

```bash
gcc main.c student.c -o slist
```

## Running the Program

Once compiled, you can run the program using:

```bash
./slist
```

### Program Menu

The program will display a menu with the following options:

1. **Add a student**: Enter details like the student's first name, last name, ID, year, and graduation year.
2. **Delete students by last name**: Enter the last name of the student(s) to be deleted.
3. **Print list forward**: Print all students from the first to the last.
4. **Print list backward**: Print all students from the last to the first.
5. **Exit**: Free all dynamically allocated memory and exit.

## Makefile

Here is the `Makefile` used for this project:

```makefile
CC = gcc
slist:
    $(CC) main.c student.c -o slist
clean:
    rm -f *.o slist
```


## License

This project is licensed under the MIT License. See the `LICENSE` file for more details.
