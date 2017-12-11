#ifndef KING_H
#define KING_H

#include "Piece.h"
#include "Helper.h"
#include <string>
#include <vector>
#include <memory>
using namespace std;

class King: public Piece{
private:

public:
  King(bool white);
  virtual ~King();

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
