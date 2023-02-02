all:
	gcc -Wall -o main main.c linkedlist.c
	
clean:
	rm -f main 