CC = gcc
CFLAGS = -Wall -g #-DNDEBUG

SRC = ex25
DEBUG = dbg
OUTNAME = out

all: $(SRC).c $ $(DEBUG).h 
	$(CC) $(CFLAGS) -c $(SRC).c -o $(SRC).o
	$(CC) $(CFLAGS) $(SRC).o -o $(OUTNAME).exe
    
.PHONY: clean
clean:
	del *.o
	del *.exe
