CC = gcc
CFLAGS = -g -Wall -fanalyzer
SRC = main
INCLUDE = ./include

.PHONY: all build run preprocess clean

all: build run


build:
	$(CC) $(CFLAGS) $(SRC).c -o $(SRC).exe -I$(INCLUDE)


run:
	./$(SRC).exe


preprocess:
	$(CC) $(CFLAGS) -E $(SRC).c -o $(SRC).preprocess -I$(INCLUDE)


clean:
	rm -f *.exe
	rm -f *.preprocess

