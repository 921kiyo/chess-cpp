#include "Queen.h"
#include "Piece.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Queen::Queen(bool white): Piece(white){
}

Queen::~Queen(){}

// bool Queen::isValidMove(){
//
// }
void Queen::calculatePossibleMove(const char* source_square, Piece* board, vector<const char*>& possible_moves){
  // Check vertical lines

  // Check horizontal lines.

  // Check giagonal lines
  for(int i = 0; i < 9; i++){
    // if not in the current position
    // if it is a blank space
    // if(board[rank][file] == EMPTY){ // or if another piece of the same color is not present.

    // }
    // If it captures an opponent's piece, then it has to stop there.
    // If the king is at a corner, you cannot go beoynd the board
  }
}

bool Queen::isKingSafe(){
  return true;
}

string Queen::getSimbol(){
  if(is_white_){
    return "WQ";
  }
  else{
    return "BQ";
  }
}
