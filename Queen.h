#ifndef QUEEN_H
#define QUEEN_H

#include "Helper.h"
#include "Piece.h"
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Queen: public Piece{
protected:
  // call the following 3 methods inside and update possible_moves vector
  // - calculateVerticalPossibleMove()
  // - calculateHorizontalPossibleMove()
  // - calculateDiagonalPossibleMove()
  virtual void calculatePossibleMove(const string source_square, \
                                     shared_ptr<Piece> board[][BOARD_LENGTH], \
                                     vector<string>& possible_moves);
public:
  Queen(bool white);

  virtual string getString();
  virtual string getSimbol();
};

#endif
