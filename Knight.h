#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"
#include "Helper.h"

#include <string>
#include <vector>
#include <memory>

using namespace std;

class Knight: public Piece{
private:

public:
  Knight(bool white);

  virtual void calculatePossibleMove(const string source_square, \
                                     shared_ptr<Piece> board[][BOARD_LENGTH], \
                                     vector<string>& possible_moves);

  void calculateLShapePossibleMove(const string source_square, \
                                   shared_ptr<Piece> board[][BOARD_LENGTH], \
                                   vector<string>& possible_moves);
  virtual string getString();
  virtual string getSimbol();
};



#endif
