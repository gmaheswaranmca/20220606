CC=gcc
SRC=main.c myutil.c
LIBSRC=book_bdb.c
LIBOBJ=book_bdb.o
LIBEXE=libbookdb.a
EXE=main
object: $(LIBSRC)
	$(CC) -g $(LIBSRC) -c
libdb:
	ar rcs $(LIBEXE) $(LIBOBJ)
build:
    $(CC) -g $(SRC) -o $(EXE) -lbookdb
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