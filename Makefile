CC = gcc
CFLAGS = -g -Wall -fanalyzer
MAIN = main

.PHONY: all main clean run

all: main

main: $(MAIN).c
	$(CC) $(CFLAGS) $(MAIN).c -o $(MAIN).exe -I./include

run: main
	./$(MAIN).exe

clean:
	rm *.exe