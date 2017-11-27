#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook:  public Piece{
protected:

public:
  Rook();
  // Can jump
  virtual bool isValidMove();
};

#endif
