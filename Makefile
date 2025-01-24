CC = gcc
CFLAGS = -g -Wall
SRC = main
LFLAGS = -lwinmm -lgdi32
LIBS = "./raylib/src/libraylib.a"

run:
	$(CC) $(CFLAGS) $(SRC).c -o $(SRC).exe
	./$(SRC).exe

# run:
# 	$(CC) $(CFLAGS) $(SRC).c "./raylib/src/libraylib.a" -o $(SRC).exe $(LFLAGS)
# 	./$(SRC).exe

# preprocess:
# 	$(CC) $(CFLAGS) -E $(SRC).c -o $(SRC).preprocess



.PHONY: clean
clean:
	rm *.exe
	rm *.preprocess

