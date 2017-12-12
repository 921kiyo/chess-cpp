#include "Helper.h"

#include <iostream>
#include <string>

using namespace std;

int getFileInt(const string square){
  return square[0] - 'A';
}
int getRankInt(const string square){
  return square[1] - '1';
}

string getStringSquare(int file, int rank){
  char source_square[3];
  source_square[0] = file + 'A';
  source_square[1] = rank + '1';
  source_square[2] = '\0';
  return source_square;
}
