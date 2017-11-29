#include "Queen.h"

#include <iostream>

using namespace std;

Queen::Queen(){

}

Queen::~Queen(){}

bool Queen::isValidMove(){

}

void Queen::calculatePossibleMove(int rank, int file, int board){
  // Check vertical lines

  // Check horizontal lines.

  // Check giagonal lines
  for(int i = 0; i < 9; i++){
    // if not in the current position
    // if it is a blank space
    if(board[rank][file] == EMPTY){ // or if another piece of the same color is not present.

    }
    // If it captures an opponent's piece, then it has to stop there.
    // If the king is at a corner, you cannot go beoynd the board
  }
}

bool Queen::isKingSafe(){
  return true;
}
