#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"
#include <string>

using namespace std;

class Rook:  public Piece{
protected:

public:
  Rook(bool white);
  virtual ~Rook();
  // Can jump
  virtual bool isValidMove();
  virtual string getSimbol();
};

#endif
