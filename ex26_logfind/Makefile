
# For windows and linux

ifeq ($(OS), Windows_NT)
	TARGETS = windows
	CLEANER = clean-windows
else
	TARGETS = linux
	CLEANER = clean-linux
endif

CC = gcc
CFLAGS = -g -Wall

SRC = main
DEBUG = dbg
OUTNAME = logfind

all: src/$(SRC).c  include/$(DEBUG).h
	$(CC) $(CFLAGS) -c src/$(SRC).c -o obj/$(SRC).o -I ./include
	$(CC) $(CFLAGS) obj/$(SRC).o -o $(OUTNAME).exe

.PHONY: clean-linux
clean-linux:
	rm -f obj/*.o *.exe

.PHONY: clean-windows
clean-windows:
	del obj\*.o
	del *.exe

.PHONY: clean
clean: $(CLEANER)

