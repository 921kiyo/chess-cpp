EXE = chess
CC = g++
CFLAGS = -Wall -g -O0 -std=c++11

SRC_DIR = src
TEST_DIR = test

SRC_FILES = $(wildcard *.cpp)
TEST_FILES = $(wildcard *cpp)

HEADER_FILES = $(wildcard *.h)

# run: $(EXE)
# 	valgrind --leak-check=full --show-leak-kinds=all  ./$(EXE) plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < input.txt > output.txt

# $(EXE): ChessMain.cpp $(SRC_FILES) $(HEADER_FILES)
# 	$(CC) $(CFLAGS) ChessMain.cpp $(SRC_FILES) -o $(EXE)

$(EXE): $(SRC_FILES) $(HEADER_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(EXE)

clean:
	rm -f $(EXE) $(wildcard *.o) $(wildcard *.gch)

.PHONY: clean
