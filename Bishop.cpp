#include "Bishop.h"
#include "Helper.h"
#include "Piece.h"
#include <iostream>
#include <string>
#include <memory>
using namespace std;

Bishop::Bishop(bool white):Piece(white){

}

void Bishop::calculatePossibleMove(const string source_square, \
                                   shared_ptr<Piece> board[][BOARD_LENGTH], \
                                   vector<string>& possible_moves){
  calculateDiagonalPossibleMove(source_square, board, possible_moves);
}

string Bishop::getString(){
  return (is_white_)? "White's Bishop": "Black's Bishop";
}

string Bishop::getSimbol(){
  return (is_white_)? "WB": "BB";
}
