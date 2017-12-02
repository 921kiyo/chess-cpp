#include "Piece.h"

#include <iostream>
#include <string>
using namespace std;

// Piece::Piece(bool white): is_white_(white){
//   is_white_ = white;
// }
Piece::Piece(bool white): is_white_(white){}

Piece::~Piece(){}

bool Piece::isValidMove(const string source_square, const string destination_square, Piece* board[8][8]){
  // DO I need const here??
  vector<string> possible_moves;

  calculatePossibleMove(source_square, board, possible_moves);
  cout << "possible_moves " << possible_moves[0] << endl;
  // If the place destination is in the possible Move, return true
  // for(const char* i: possible_moves){
  //   if(source_square == i)
  // }
  // Check if the move makes the king in check.
  // isKingSafe()

  // Or Castling
  return true;
}

bool Piece::getIsWhite(){
  return is_white_;
}
