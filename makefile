CC = g++

FLAGS = -Wall -Wextra -g -std=c++14
CFLAGS = -c $(FLAGS)
LFLAGS = $(FLAGS)

OBJS = build/repl_tools.o \
       build/engine.o \
       build/lexer.o \
       build/ast.o \
       build/error.o

all: Godel

Godel: src/main.cpp $(OBJS)
	$(CC) $(LFLAGS) src/main.cpp build/*.o -o bin/Godel -lreadline

build/repl_tools.o: src/repl_tools.*
	$(CC) $(CFLAGS) src/repl_tools.cpp -o build/repl_tools.o

build/engine.o: src/engine.* build/lexer.o build/ast.o build/error.o
	$(CC) $(CFLAGS) src/engine.cpp -o build/parser.o

build/lexer.o: src/lexer.* build/error.o
	$(CC) $(CFLAGS) src/lexer.cpp -o build/lexer.o

build/ast.o: src/ast.* build/error.o
	$(CC) $(CFLAGS) src/ast.cpp -o build/ast.o

build/error.o: src/error.*
	$(CC) $(CFLAGS) src/error.cpp -o build/error.o

clean:
	rm -rf build/*
	rm -rf bin/*
