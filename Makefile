CFLAGS = -Wall -Werror -std=c++17
OBJ = g++ $(CFLAGS) -c $< -o $@
TEST = g++ $(CFLAGS) -I ..third/catch2 -c $< -o $@

.PHONY: clean

all: help

build: folder1 folder2 folder3 folder4 bin/Keyboard-Ninja

test: bin/Keyboard-Ninja-test

folder1:	
	mkdir -p build

folder2:
	mkdir -p bin
	
folder3:
	mkdir -p build/src
	
folder4:
	mkdir -p build/test
	
bin/Keyboard-Ninja: build/src/kmenu.o build/src/Main.o build/src/typing_tutor.o build/src/Numerical_simulator.o
	g++ $(CFLAGS) $^ -lncurses -o $@
	
build/src/kmenu.o: sourcs/src/kmenu.cpp
	$(OBJ) -lncurses
	
build/src/Main.o: sourcs/src/Main.cpp
	$(OBJ) -lncurses

build/src/typing_tutor.o: sourcs/src/typing_tutor.cpp
	$(OBJ) -lncurses

build/src/Numerical_simulator.o: sourcs/src/Numerical_simulator.cpp
	$(OBJ) -lncurses



bin/Keyboard-Ninja-test: build/test/reaction.o build/test/printWelcomePanel.o build/test/test_level1.o build/test/Lessen1.o
	g++ $(CFLAGS) $^ -o $@

build/test/reaction.o: sourcs/test/reaction.cpp
	$(TEST)
	
build/test/printWelcomePanel.o: sourcs/test/printWelcomePanel.cpp
	$(TEST)

build/test/test_level1.o: sourcs/test/test_level1.cpp
	$(TEST)

build/test/Lessen1.o: sourcs/test/Lessen1.cpp
	$(TEST)
	
copyDLL: 
	cp third/pdcurses.dll bin
	
copyTXT: 
	cp sourcs/Welcome.txt bincp 
	cp sourcs/data/level1.txt bin
	cp sourcs/data/level2.txt bin
	cp sourcs/data/level3.txt bin
	cp sourcs/data/level4.txt bin
	cp sourcs/data/level5.txt bin
	cp sourcs/data/level6.txt bin

run:
	bin/Keyboard-Ninja.exe Welcome.txt

clean:
	rm -r build

help:
	@echo "=========================HELP THERE!========================="
	@echo ""
	@echo "1. Build project: Make build"
	@echo "2. Test: Make test"
	@echo "3. If you see error 'pdcurses.dll not found': Make copyDLL"
	@echo ""
	@echo "=========================    TODO   ========================="
