CC = gcc
CC_FLAGS = -Wall
EXE = fifo

all: run

run: compile
	./$(EXE)

compile:
	$(CC) $(CC_FLAGS) src/*.c -o $(EXE)