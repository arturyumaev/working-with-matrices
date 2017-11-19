all: main.exe


COMP_CMDS=gcc -std=c99 -c -Wall -Werror

main.exe: addition.o main.o inverse.o multiplication.o read_matr.o write_matr.o allocate_memory.o
	gcc addition.o inverse.o multiplication.o read_matr.o allocate_memory.o write_matr.o main.o -o main.exe

addition.o: addition.c
	$(COMP_CMDS) addition.c

main.o: main.c
	$(COMP_CMDS) main.c

inverse.o: inverse.c
	$(COMP_CMDS) inverse.c

multiplication.o: multiplication.c
	$(COMP_CMDS) multiplication.c

read_matr.o: read_matr.c
	$(COMP_CMDS) read_matr.c

write_matr.o: write_matr.c
	$(COMP_CMDS) write_matr.c

allocate_memory.o: allocate_memory.c
	$(COMP_CMDS) allocate_memory.c 

clean:
	rm *.o *.exe
