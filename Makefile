CFLAGS = -Wall -Werror -std=c++17
OBJ = g++ $(CFLAGS) -c $< -o $@
TEST = g++ $(CFLAGS) -I ..third/catch2 -c $< -o $@
allFolders  = folder1 folder2 folder3 folder4 folder5
allO = build/src/Main.o build/src/kmenu.o build/src/typing_tutor.o build/src/Numerical_simulator.o
allTests = build/test/reaction.o build/test/getXX.o build/test/getYY.o build/test/coordinate_test.o build/test/result_test.o build/test/num_tests.o build/test/printWelcomePanel.o


.PHONY: clean

##############################
all: build test run-tests run# 
##############################

build: $(allFolders) bin/Keyboard-Ninja copyTXT

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

bin/Keyboard-Ninja: $(allO)
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

bin/Keyboard-Ninja-test: $(allTests)
	g++ $(CFLAGS) build/src/kmenu.o build/src/typing_tutor.o build/src/Numerical_simulator.o -lncurses $^ -o $@

build/test/reaction.o: sourcs/test/reaction.cpp
	$(TEST)
	
build/test/printWelcomePanel.o: sourcs/test/printWelcomePanel.cpp
	$(TEST)
	
build/test/getXX.o: sourcs/test/getXX.cpp
	$(TEST)
	
build/test/getYY.o: sourcs/test/getYY.cpp
	$(TEST)

build/test/coordinate_test.o: sourcs/test/coordinate_test.cpp
	$(TEST)

build/test/result_test.o: sourcs/test/result_test.cpp
	$(TEST)

build/test/num_tests.o: sourcs/test/num_tests.cpp
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
	@echo "|                                                           |"
	@echo "|  1. Build project: Make build                             |"
	@echo "|  2. Test: Make test                                       |"
	@echo "|  3. Claen: make clean                                     |"
	@echo "|                                                           |"
	@echo "============================================================="