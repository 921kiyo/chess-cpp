#ifndef KING_H
#define KING_H

#include "Piece.h"
#include "Definitions.h"
#include <string>
#include <vector>

using namespace std;

class King: public Piece{
private:

public:
  King(bool white);
  virtual ~King();

  virtual void calculatePossibleMove(const string source_square, \
                                     Piece* board[8][8], \
                                     vector<string>& possible_moves);

  void calculateAdjacentPossibleMove(const string source_square, \
                                     Piece* board[8][8], \
                                     vector<string>& possible_moves);

  void checkCastling(const string source_square, Piece* board[8][8], \
                     vector<string>& possible_moves);
  virtual string getString();
  virtual string getSimbol();
};

#endif
