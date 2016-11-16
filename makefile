CC = g++

FLAGS = -Wall -Wextra -g -std=c++14
CFLAGS = -c $(FLAGS)
LFLAGS = $(FLAGS)

all: Godel

Godel: src/main.cpp build/repl_tools.o
	$(CC) $(LFLAGS) src/main.cpp build/*.o -o bin/Godel -lreadline

build/repl_tools.o: src/repl_tools.*
	$(CC) $(CFLAGS) src/repl_tools.cpp -o build/repl_tools.o

clean:
	rm -rf build/*
	rm -rf bin/*
