
#include "Pawn.h"
#include "Piece.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
Pawn::Pawn(bool white): Piece(white){}

void Pawn::calculatePossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves){
  calculatePawnPossibleMove(source_square, board, possible_moves);
}
string Pawn::getSimbol(){
  if(is_white_){
    return "WP";
  }
  else{
    return "BP";
  }
}
