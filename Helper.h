#ifndef HELPER_H
#define HELPER_H

#include <string>

using namespace std;

const int BOARD_LENGTH = 8;

// Get an integer value for file
int getFileInt(string square);
// Get an integer value for rank
int getRankInt(string square);

// Get the correct string format, which is the same as submitMove string,
// from file and rank integers.
string getStringSquare(int file, int rank);

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
