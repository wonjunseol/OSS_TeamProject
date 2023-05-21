CC=gcc
system : main.c penalty.o
        $(CC) -o system main.c penalty.o
penalty.o : penalty.c penalty.h
        $(CC) -c penalty.c -o penalty.o
clean:
        rm *.o system *.txt
