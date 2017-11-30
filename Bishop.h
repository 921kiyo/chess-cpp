#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"
#include <string>

using namespace std;

class Bishop: public Piece{
protected:

public:
  Bishop(bool white);
  // Can jump
  virtual ~Bishop();
  virtual bool isValidMove();
  virtual string getSimbol();
};

#endif
