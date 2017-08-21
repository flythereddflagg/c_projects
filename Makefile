CC = gcc
CFLAGS = -Wall -g

SRC = ex17

all: $(SRC).c
	$(CC) $(CFLAGS) $(SRC).c -o $(SRC).exe
    
.PHONY: clean
clean:
	del *.exe
