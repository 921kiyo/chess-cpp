#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"
#include <string>
#include <vector>

using namespace std;

class Rook:  public Piece{
public:
  Rook(bool white);
  virtual ~Rook();
  virtual void calculatePossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves);
  virtual string getSimbol();
};

#endif
