EXE = chess
CC = g++
# CFLAGS = -I../include -Wall -g -O0 -std=c++11
CFLAGS = -Wall -g -O0 -std=c++11

SRC_DIR = src
TEST_DIR = test

# SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
# TEST_FILES = $(wildcard $(TEST_DIR)/*cpp)
SRC_FILES = $(wildcard *.cpp)
TEST_FILES = $(wildcard *cpp)


# Exclude tester.cpp
TEST_FILES := $(filter-out $(TEST_DIR)/tester.cpp, $(TEST_FILES))
# HEADER_FILES = $(wildcard $(INC_DIR)/*.h)
HEADER_FILES = $(wildcard *.h)

# run: $(EXE)
# 	valgrind --leak-check=full --show-leak-kinds=all  ./$(EXE) plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < input.txt > output.txt

# $(EXE): ChessMain.cpp $(SRC_FILES) $(HEADER_FILES)
# 	$(CC) $(CFLAGS) ChessMain.cpp $(SRC_FILES) -o $(EXE)

$(EXE): $(SRC_FILES) $(HEADER_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(EXE)


# tester.o: $(TEST_DIR)/tester.cpp
# 	$(CC) -o tester.o -c $(TEST_DIR)/tester.cpp $(CFLAGS)
#
# tester: tester.o $(TEST_FILES) $(SRC_FILES) $(HEADER_FILES)
# 	$(CC) -o tester $(TEST_FILES) tester.o $(SRC_FILES) $(CFLAGS)

clean:
	rm -f $(EXE) $(wildcard *.o) $(wildcard *.gch) tester tester.o

.PHONY: clean test
