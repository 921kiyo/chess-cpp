#include "Helper.h"
#include "Rook.h"
#include "Piece.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

Rook::Rook(bool white): Piece(white){
}

void Rook::calculatePossibleMove(const string source_square, \
                                 shared_ptr<Piece> board[][BOARD_LENGTH], \
                                 vector<string>& possible_moves){
  calculateVerticalPossibleMove(source_square, board, possible_moves);
  calculateHorizontalPossibleMove(source_square, board, possible_moves);
}

string Rook::getString(){
  return (is_white_)? "White's Rook": "Black's Rook";
}

string Rook::getSimbol(){
  return (is_white_)? "WR": "BR";
}
