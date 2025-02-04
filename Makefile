CC = gcc
CFLAGS = -g -Wall
SRC = main

.PHONY: all build run preprocess clean

all: build run


build:
	$(CC) $(CFLAGS) $(SRC).c -o $(SRC).exe


run:
	./$(SRC).exe


preprocess:
	$(CC) $(CFLAGS) -E $(SRC).c -o $(SRC).preprocess


clean:
	rm -f *.exe
	rm -f *.preprocess

