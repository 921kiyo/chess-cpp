#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop: public Piece{
protected:

public:
  Bishop(bool white);
  // Can jump
  virtual ~Bishop();
  virtual bool isValidMove();
};

#endif
