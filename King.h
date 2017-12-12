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

  // call calculatePawnPossibleMove() inside the method and
  // update possible_moves vector
  virtual void calculatePossibleMove(const string source_square, \
                                     shared_ptr<Piece> board[][BOARD_LENGTH], \
                                     vector<string>& possible_moves);
  // Check all adjacent squares and update the possible_moves vector
  // Wether the king will be safe after the move
  // is not being checked in this method, and will be check in ChessBoard class
  void calculateAdjacentPossibleMove(const string source_square, \
                                     shared_ptr<Piece> board[][BOARD_LENGTH], \
                                     vector<string>& possible_moves);

  virtual string getString();
  virtual string getSimbol();
};

#endif
