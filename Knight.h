#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"
#include "Definitions.h"
#include <string>
#include <vector>

using namespace std;

class Knight: public Piece{
private:

public:
  Knight(bool white);
  virtual string getSimbol();

  virtual void calculatePossibleMove(const string source_square, \
                                     Piece* board[8][8], \
                                     vector<string>& possible_moves);

  void calculateLShapePossibleMove(const string source_square, \
                                   Piece* board[8][8], \
                                   vector<string>& possible_moves);
};



#endif
