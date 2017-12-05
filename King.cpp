
#include "King.h"
#include "Piece.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

King::King(bool white):Piece(white){}

King::~King(){}

string King::getSimbol(){
  if(is_white_){
    return "WK";
  }
  else{
    return "BK";
  }
}

void King::calculatePossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves){
  calculateAdjacentPossibleMove(source_square, board, possible_moves);
  //   // If the king is at a corner, you cannot go beoynd the board
}
