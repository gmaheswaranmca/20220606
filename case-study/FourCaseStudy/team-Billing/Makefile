CC=gcc
SRC=main.c  db.c myutil.c
EXE=main
build:
	$(CC) -g $(SRC) -o $(EXE)
run:
	./$(EXE)
clean:
	rm -f *.o *.s *.i $(EXE)
lint:
	splint  *.c
check:
	valgrind --leak-check=yes ./$(EXE)
execute: clean build run
memcheck: clean build check
