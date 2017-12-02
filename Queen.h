#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"
#include <string>
#include <vector>
using namespace std;

class Queen: public Piece{
protected:

public:
  Queen(bool white);
  // Can jump
  virtual ~Queen();
  // virtual bool isValidMove();
  virtual void calculatePossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves);
  bool isKingSafe();
  virtual string getSimbol();
};

#endif
