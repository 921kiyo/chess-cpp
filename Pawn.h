#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
#include "Helper.h"
#include <string>
#include <vector>

using namespace std;

class Pawn: public Piece{
private:

public:
  Pawn(bool white);
  virtual void calculatePossibleMove(const string source_square, \
                                     Piece* board[8][8], \
                                     vector<string>& possible_moves);
  void calculatePawnPossibleMove(const string source_square, \
                                 Piece* board[8][8], \
                                 vector<string>& possible_moves);
  virtual string getString();
  virtual string getSimbol();
};

#endif
