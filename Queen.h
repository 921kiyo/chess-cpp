#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"

class Queen: public Piece{
protected:

public:
  Queen();
  // Can jump
  virtual bool isValidMove();
};

#endif
