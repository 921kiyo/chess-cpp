#include "Helper.h"
#include "Piece.h"
#include "Queen.h"

#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

Queen::Queen(bool white): Piece(white){
}

void Queen::calculatePossibleMove(const string source_square, \
                                  shared_ptr<Piece> board[][BOARD_LENGTH], \
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
