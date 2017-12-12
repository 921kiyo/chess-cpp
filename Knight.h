#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"
#include "Helper.h"

#include <string>
#include <vector>
#include <memory>

using namespace std;

class Knight: public Piece{
protected:
  // call calculateLShapePossibleMove() inside the method and
  // update possible_moves vector
  virtual void calculatePossibleMove(const string source_square, \
                                     shared_ptr<Piece> board[][BOARD_LENGTH], \
                                     vector<string>& possible_moves);
  // Check all possible moves given the current situation of the board
  // and update the possible_moves vector
  void calculateLShapePossibleMove(const string source_square, \
                                   shared_ptr<Piece> board[][BOARD_LENGTH], \
                                   vector<string>& possible_moves);
public:
  Knight(bool white);
  virtual string getString();
  virtual string getSimbol();
};



#endif
