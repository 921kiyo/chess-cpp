#ifndef KING_H
#define KING_H

#include "Helper.h"
#include "Piece.h"

#include <string>
#include <vector>
#include <memory>
using namespace std;

class King: public Piece{
private:

public:
  King(bool white);

  virtual void calculatePossibleMove(const string source_square, \
                                     shared_ptr<Piece> board[][BOARD_LENGTH], \
                                     vector<string>& possible_moves);

  void calculateAdjacentPossibleMove(const string source_square, \
                                     shared_ptr<Piece> board[][BOARD_LENGTH], \
                                     vector<string>& possible_moves);

  virtual string getString();
  virtual string getSimbol();
};

#endif
