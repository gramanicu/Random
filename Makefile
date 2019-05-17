# Copyright 2019 Grama Nicolae

.PHONY: gitignore clean memory beauty run
.SILENT: beauty clean memory gitignore

# Compilation variables
CC = g++
CFLAGS = -Wno-unused-parameter -Wall -Wextra -pedantic -g -O3 -std=c++11
EXE = bin/main
LIB = lib/libeasyrand.so
SRC = sources/EasyRand.cpp
OBJ = $(SRC:.cpp=.o)

# Compiles the library
build: bin/EasyRand.o
	$(info Compiling library...)
	@if [ ! -d "./lib" ]; then mkdir ./lib; fi ||:
	@$(CC) -shared -o $(LIB) $^ $(CFLAGS) -fpic ||:
	-@rm -f *.o ||:

# Compiles the object files for the library
bin/EasyRand.o: sources/EasyRand.cpp
	@if [ ! -d "./bin" ]; then mkdir ./bin; fi ||:
	@$(CC) -o $@ -c $< $(CFLAGS) -fpic ||:

# Test the project
test: build bin/test.o
	$(info Compiling test...)
	@if [ ! -d "./bin" ]; then mkdir ./bin; fi ||:
	@$(CC) -L./lib -Wl,-rpath=./lib -o $(EXE) bin/test.o $(CFLAGS) -leasyrand ||:
	-@rm -f *.o ||:
	$(info Started test)
	@./$(EXE) ||:

bin/test.o: sources/test.cpp
	@if [ ! -d "./bin" ]; then mkdir ./bin; fi ||:
	@$(CC) -o $@ -c $< $(CFLAGS) ||:

 

# Deletes the binary and object files
clean:
	rm -f $(EXE) */*.o $(LIB)
	echo "Deleted the binary and object files"

# Automatic coding style
beauty:
	clang-format -i -style=file sources/*.cpp
	clang-format -i -style=file headers/*.h
	
# Checks the memory for leaks
MFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes
memory:build
	valgrind $(MFLAGS) ./$(EXE)

# Adds and updates gitignore rules
gitignore:
	@echo "$(EXE)" >> .gitignore ||:
	@echo "sources/*.o" >> .gitignore ||:
	@echo "lib/*.so" >> .gitignore ||:
	@echo ".vscode*" >> .gitignore ||:	
	echo "Updated .gitignore"