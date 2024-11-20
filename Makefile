$(CC) = gcc
slist:
	gcc main.c student.c -o slist
Clean:
	rm *.o slist
