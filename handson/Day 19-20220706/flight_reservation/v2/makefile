CC=gcc
SRC=app.c flight_controller.c
DBSRC=flight_db.c 
DBOBJ=flight_db.o 
UISRC=flight_ui.c 
UIOBJ=flight_ui.o
EXE=main
DBEXE=libdb.a
UIEXE=libui.a
libdb_compile:
	$(CC) -g $(DBSRC) -c
libdb_build: libdb_compile
	ar rcs $(DBEXE) $(DBOBJ) 
libui_compile:
	$(CC) -g $(UISRC) -c 
libui_build: libui_compile
	ar rcs $(UIEXE) $(UIOBJ) 
build:
	$(CC) -g $(SRC) -o $(EXE) -L. $(DBEXE) $(UIEXE) 
run:
	./$(EXE)
clean:
	rm -f *.o *.s *.i *.a $(EXE)
lint:
	splint  *.c
check:
	valgrind --leak-check=yes --show-leak-kind=all ./$(EXE)
build_all: libdb_build libui_build build
	ls -l
clean_build: clean build_all	
execute: clean_build run
memcheck: clean_build check
