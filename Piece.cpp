#include "Piece.h"

#include <iostream>
using namespace std;

Piece::Piece(bool white){
  is_white_ = white;
}

Piece::~Piece(){}

bool Piece::isValidMove(const char* source_square, const char* destination_square, Piece* board[8][8]){
  vector<const char*> possible_moves;

  calculatePossibleMove(source_square, board, possible_moves);
  cout << "possible_moves " << possible_moves[1] << endl;
  // If the place destination is in the possible Move, return true
  // for(const char* i: possible_moves){
  //   if(source_square == i)
  // }
  // Check if the move makes the king in check.
  // ifKingSafe()

  // Or Castling
  return true;
}

bool Piece::getIsWhite(){
  return is_white_;
}
