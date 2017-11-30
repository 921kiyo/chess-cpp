#include "Piece.h"

#include <iostream>
using namespace std;

Piece::Piece(bool white){
  is_white_ = white;
}

Piece::~Piece(){}

bool Piece::isValidMove(const char* source_square, const char* destination_square, Piece* board[8][8]){
  vector<const char*> possible_moves;

  // calculatePossibleMove(source_square, board, possible_moves);
  // If the place destination is in the possible Move, return true

  // Check if the move makes the king in check.
  // ifKingSafe()

  // Or Castling
  return true;
}
