#include "Bishop.h"
#include "Piece.h"
#include <iostream>
#include <string>
using namespace std;

Bishop::Bishop(bool white):Piece(white){

}
Bishop::~Bishop(){}

void Bishop::calculatePossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves){
  calculateDiagonalPossibleMove(source_square, board, possible_moves);
}

string Bishop::getSimbol(){
  if(is_white_){
    return "WB";
  }
  else{
    return "BB";
  }
}
