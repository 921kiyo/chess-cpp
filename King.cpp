
#include "King.h"

#include <iostream>

using namespace std;

King::King(){}

King::~King(){}

bool King::isValidMove(){
  // calculatePossibleMove();
  // If the place destination is in the possible Move, return true

  // Check if the move makes the king in check.
  // ifKingSafe()

  // Or Castling
  return true;
}

void King::calculatePossibleMove(int rank, int file, int board){
  for(int i = 0; i < 9; i++){
    // if not in the current position
    // if it is a blank space
    if(board[rank][file] == EMPTY){ // or if another piece of the same color is not present.

    }
    // If the king is at a corner, you cannot go beoynd the board 
  }
}

bool King::isKingSafe(){
  return true;
}
