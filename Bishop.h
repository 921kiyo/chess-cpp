#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop: public Piece{
protected:

public:
  Bishop();
  // Can jump
  virtual bool isValidMove();
};

#endif
