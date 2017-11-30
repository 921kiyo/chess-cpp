
#include "King.h"
#include "Piece.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

King::King(bool white):Piece(white){}

King::~King(){}

// bool King::isValidMove(const char* source_square, const char* destination_square, Piece* board){
//   vector<const char*> possible_moves;
//
//   calculatePossibleMove(source_square, board, possible_moves);
//   // If the place destination is in the possible Move, return true
//
//   // Check if the move makes the king in check.
//   // ifKingSafe()
//
//   // Or Castling
//   return true;
// }

string King::getSimbol(){
  if(is_white_){
    return "WK";
  }
  else{
    return "BK";
  }
}

void King::calculatePossibleMove(const char* source_square, Piece* board[8][8], vector<const char*>& possible_moves){
  int rank = source_square[1] - '1';
  int file = source_square[0] - 'A';
  cout << "rank " << rank << endl;
  cout << "file " << file << endl;

  for(int i = 0; i < 9; i++){
    // if not in the current position
    // if it is a blank space
    // or if another piece of the same color is not present.
    // If the king is at a corner, you cannot go beoynd the board
  }
}

// bool King::isKingSafe(){
//   return true;
// }
