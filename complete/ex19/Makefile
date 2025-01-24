CC = gcc
CFLAGS = -Wall -g #-DNDEBUG

SRC = ex19
DEBUG = dbg

all: $(SRC).c $(DEBUG).h 
	$(CC) $(CFLAGS) $(SRC).c -o $(SRC).exe
    
.PHONY: clean
clean:
	del *.exe
