EXE = chess
CC = g++
CFLAGS = -Wall -g -O0 -std=c++11

SRC_DIR = src
TEST_DIR = test

SRC_FILES = $(wildcard *.cpp)
TEST_FILES = $(wildcard *cpp)

HEADER_FILES = $(wildcard *.h)

# run: $(EXE)
# 	valgrind --leak-check=full --show-leak-kinds=all  ./$(EXE)

$(EXE): $(SRC_FILES) $(HEADER_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(EXE)

clean:
	rm -f $(EXE) $(wildcard *.o) $(wildcard *.gch)

.PHONY: clean
