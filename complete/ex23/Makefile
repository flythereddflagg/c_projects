CC = gcc
CFLAGS = -Wall -g -DNDEBUG

SRC = ex23
DEBUG = dbg
OUTNAME = ex23

all: $(SRC).c $ $(DEBUG).h 
	$(CC) $(CFLAGS) -c $(SRC).c -o $(SRC).o
	$(CC) $(CFLAGS) $(SRC).o -o $(OUTNAME).exe
    
.PHONY: clean
clean:
	del *.o
	del *.exe
