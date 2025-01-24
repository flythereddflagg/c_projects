CC = gcc
CFLAGS = -Wall -g -DNDEBUG

SRC = main
EXTRA = ex22
DEBUG = dbg
OUTNAME = ex22

all: $(SRC).c $(EXTRA).h $(EXTRA).h $(DEBUG).h 
	$(CC) $(CFLAGS) -c $(SRC).c -o $(SRC).o
	$(CC) $(CFLAGS) -c $(EXTRA).c -o $(EXTRA).o
	$(CC) $(CFLAGS) $(SRC).o $(EXTRA).o -o $(OUTNAME).exe
    
.PHONY: clean
clean:
	del *.o
	del *.exe
