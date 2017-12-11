#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Bishop: public Piece{
public:
  Bishop(bool white);
  virtual ~Bishop();
  virtual void calculatePossibleMove(const string source_square, \
                                     shared_ptr<Piece> board[8][8], \
                                     vector<string>& possible_moves);
  virtual string getString();
  virtual string getSimbol();
};

#endif
