#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"
#include <string>

using namespace std;

class Queen: public Piece{
protected:

public:
  Queen(bool white);
  // Can jump
  virtual ~Queen();
  virtual bool isValidMove();
  void calculatePossibleMove(int rank, int file, int board);
  bool isKingSafe();
  virtual string getSimbol();
};

#endif
