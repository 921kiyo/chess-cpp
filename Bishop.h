#ifndef BISHOP_H
#define BISHOP_H

#include "Helper.h"
#include "Piece.h"

#include <string>
#include <vector>
#include <memory>
using namespace std;

class Bishop: public Piece{
public:
  Bishop(bool white);
  // call calculateDiagonalPossibleMove() inside the method and
  // update possible_moves vector
  virtual void calculatePossibleMove(const string source_square, \
                                     shared_ptr<Piece> board[][BOARD_LENGTH], \
                                     vector<string>& possible_moves);
  virtual string getString();
  virtual string getSimbol();
};

#endif
