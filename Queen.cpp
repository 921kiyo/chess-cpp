#include "Queen.h"
#include "Piece.h"
#include "Definitions.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Queen::Queen(bool white): Piece(white){
}

Queen::~Queen(){}

void Queen::calculatePossibleMove(const string source_square, \
                                  Piece* board[8][8], \
                                  vector<string>& possible_moves){
  calculateVerticalPossibleMove(source_square, board, possible_moves);
  calculateHorizontalPossibleMove(source_square, board, possible_moves);
  calculateDiagonalPossibleMove(source_square, board, possible_moves);
}

string Queen::getString(){
  return (is_white_)? "White's Queen": "Black's Queen";
}

string Queen::getSimbol(){
  return (is_white_)? "WQ": "BQ";
}
