#include "Piece.h"

#include <iostream>
#include <string>
using namespace std;

Piece::Piece(bool white): is_white_(white), is_first_move_(true){}

Piece::~Piece(){}

bool Piece::isValidMove(const string source_square, const string destination_square, Piece* board[8][8]){
  // DO I need const here??
  vector<string> possible_moves;

  calculatePossibleMove(source_square, board, possible_moves);
  // C++11 Range-based loop
  for(string square: possible_moves){
    cout << "sq " << square << endl;
    if(destination_square == square){
      cout << "yes" << endl;
      return true;
    }

  }

  return false;

  // Check if the move makes the king in check.
  // isKingSafe()

  // Or Castling
}

bool Piece::getIsWhite(){
  return is_white_;
}

void Piece::negateIsFirstMove(){
  if(is_first_move_){
    is_first_move_ = false;
  }
}

bool isKingSafe(const string king_position){
  
}
