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
  virtual void calculatePossibleMove(const char* source_square, Piece* board, vector<const char*>& possible_moves);
  bool isKingSafe();
  virtual string getSimbol();
};

#endif
