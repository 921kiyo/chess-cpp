#ifndef DEFINITION_H
#define DEFINITION_H

#include <string>
using namespace std;

const int NUM_OF_PIECES = 12;
// TODO use this
const int BOARD_LENGTH = 8;

static int getFileInt(string square){
  return square[0] - 'A';
}
static int getRankInt(string square){
  return square[1] - '1';
}

static string getStringSquare(int file, int rank){
  char source_square[3];
  source_square[0] = file + 'A';
  source_square[1] = rank + '1';
  source_square[2] = '\0';
  return source_square;
}

enum FileEnum {
  FILE_A,
  FILE_B,
  FILE_C,
  FILE_D,
  FILE_E,
  FILE_F,
  FILE_G,
  FILE_H,
  FILE_NONE
};

enum RankEnum {
  RANK_1,
  RANK_2,
  RANK_3,
  RANK_4,
  RANK_5,
  RANK_6,
  RANK_7,
  RANK_8,
  RANK_NONE
};

#endif
