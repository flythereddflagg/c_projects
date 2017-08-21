CC = gcc
CFLAGS = -Wall -g #-DNDEBUG

SRC = ex24
DEBUG = dbg
OUTNAME = ex24

all: $(SRC).c $ $(DEBUG).h 
	$(CC) $(CFLAGS) -c $(SRC).c -o $(SRC).o
	$(CC) $(CFLAGS) $(SRC).o -o $(OUTNAME).exe
    
.PHONY: clean
clean:
	del *.o
	del *.exe
