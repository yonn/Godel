CC = g++

FLAGS = -Wall -Wextra -g -std=c++14
CFLAGS = -c $(FLAGS)
LFLAGS = $(FLAGS)

OBJS = build/repl_tools.o \
       build/lexer.o \
       build/error.o

all: Godel

Godel: src/main.cpp $(OBJS)
	$(CC) $(LFLAGS) src/main.cpp build/*.o -o bin/Godel -lreadline

build/repl_tools.o: src/repl_tools.*
	$(CC) $(CFLAGS) src/repl_tools.cpp -o build/repl_tools.o

build/lexer.o: src/lexer.* src/error.cpp
	$(CC) $(CFLAGS) src/lexer.cpp -o build/lexer.o

build/error.o: src/error.*
	$(CC) $(CFLAGS) src/error.cpp -o build/error.o

clean:
	rm -rf build/*
	rm -rf bin/*
