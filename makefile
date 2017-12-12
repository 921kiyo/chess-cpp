EXE = chess
CC = g++
CFLAGS = -Wall -g -O0 -std=c++11

SRC_DIR = src

SRC_FILES = $(wildcard *.cpp)

HEADER_FILES = $(wildcard *.h)

$(EXE): $(SRC_FILES) $(HEADER_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(EXE)

clean:
	rm -f $(EXE) $(wildcard *.o) $(wildcard *.gch)

.PHONY: clean
