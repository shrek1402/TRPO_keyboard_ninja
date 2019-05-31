CFLAGS = -Wall -Werror -std=c++17
OBJ = g++ $(CFLAGS) -c $< -o $@
TEST = g++ $(CFLAGS) -I ..third/catch2 -c $< -o $@

.PHONY: clean

##############################
all: build test run-tests run# 
##############################

build: folder1 folder2 folder3 folder4 folder5 bin/Keyboard-Ninja copyTXT

test: bin/Keyboard-Ninja-test


############################  FOLDER  ############################

folder1:	
	mkdir -p build

folder2:
	mkdir -p bin
	
folder3:
	mkdir -p build/src
	
folder4:
	mkdir -p build/test

folder5:
	mkdir -p bin/data
	
	
############################  BUILD  ############################

bin/Keyboard-Ninja: build/src/Main.o build/src/kmenu.o build/src/typing_tutor.o build/src/Numerical_simulator.o
	g++ $(CFLAGS) $^ -lncurses -o $@ 
	
build/src/kmenu.o: sourcs/src/kmenu.cpp
	$(OBJ) -lncurses
	
build/src/Main.o: sourcs/src/Main.cpp
	$(OBJ) -lncurses

build/src/typing_tutor.o: sourcs/src/typing_tutor.cpp
	$(OBJ) -lncurses

build/src/Numerical_simulator.o: sourcs/src/Numerical_simulator.cpp
	$(OBJ) -lncurses



############################  TEST  ############################

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

run-tests:
	bin/Keyboard-Ninja-test
	
############################  OTHER  ############################	
	
run: bin/Keyboard-Ninja
	
copyDLL: 
	cp third/pdcurses.dll bin
	
copyTXT: 
	cp sourcs/data/*.txt bin/data

clean:
	rm -r build
	rm -r bin

help:
	@echo "=========================HELP THERE!========================="
	@echo ""
	@echo "1. Build project: Make build"
	@echo "2. Test: Make test"
	@echo "3. Claen: make clean"
	@echo ""
	@echo "=========================    TODO   ========================="
