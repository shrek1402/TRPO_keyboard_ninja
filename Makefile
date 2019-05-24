CFLAGS = -Wall -Werror -std=c++17 #-Ithird/
OBJ = g++ $(CFLAGS) -c $< -o $@
TEST =

.PHONY: clean

all: help

build: folder1 folder2 bin/Keyboard-Ninja.exe copyTXT

folder1:	
	mkdir -p build

folder2:
	mkdir -p bin
	
bin/Keyboard-Ninja.exe: build/kmenu.o build/Main.o build/typing_tutor.o
	g++ $(CFLAGS) third/pdcurses.dll $^ -o $@

	
build/kmenu.o: sourcs/kmenu.cpp
	$(OBJ) -lncurses
	
build/Main.o: sourcs/Main.cpp
	$(OBJ) -lncurses

build/typing_tutor.o: sourcs/typing_tutor.cpp
	$(OBJ) -lncurses

copyDLL: 
	cp third/pdcurses.dll bin
	
copyTXT: 
	cp sourcs/Welcome.txt bin

run:
	bin/Keyboard-Ninja.exe Welcome.txt

help:
	@echo "=========================HELP THERE!========================="
	@echo ""
	@echo "1. Build project: Make build"
	@echo "2. Test: Make test"
	@echo "3. If you see error 'pdcurses.dll not found': Make copyDLL"
	@echo ""
	@echo "=========================    TODO   ========================="

