#ifndef ROOK_H
#define ROOK_H

#include "Helper.h"
#include "Piece.h"
#include <string>
#include <vector>

using namespace std;

class Rook:  public Piece{
public:
  Rook(bool white);
  virtual ~Rook();
  virtual void calculatePossibleMove(const string source_square, \
                                     shared_ptr<Piece> board[][BOARD_LENGTH], \
                                     vector<string>& possible_moves);
  virtual string getString();
  virtual string getSimbol();
};

#endif
