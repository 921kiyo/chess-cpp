#include "Piece.h"
#include "Definitions.h"

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
    if(destination_square == square){
      return true;
    }
  }
  return false;
}

bool Piece::isWhite(){
  return is_white_;
}

void Piece::negateIsFirstMove(){
  if(is_first_move_){
    is_first_move_ = false;
  }
}

bool Piece::isDestinationEmpty(int rank, int file, bool is_white, Piece* board[8][8], vector<string>& possible_moves){
  string sq;
  if(rank < RANK_1 || rank > RANK_8 || file < FILE_A || file > FILE_H){
    return false;
  }
  if(board[rank][file] != nullptr && is_white == board[rank][file]->isWhite()){
    return false;
  }
  else if(board[rank][file] != nullptr && is_white != board[rank][file]->isWhite()){
    sq = getStringSquare(file, rank);
    possible_moves.push_back(sq);
    return false;
  }
  else if(board[rank][file] == nullptr){
     sq = getStringSquare(file, rank);
     possible_moves.push_back(sq);
     return true;
  }
  return false;
}

void Piece::calculateVerticalPossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves){
  int file = getFileInt(source_square);
  int rank = getRankInt(source_square);
  bool is_white = board[rank][file]->isWhite();
  // Check vertical lines to the top
  for(int r = rank+1; r <= RANK_8; r++){
    if(!isDestinationEmpty(r, file, is_white, board, possible_moves)){
      break;
    }
  }
  // Check vertical line to the bottom
  for(int r = rank-1; r >= RANK_1; r--){
    if(!isDestinationEmpty(r, file, is_white, board, possible_moves)){
      break;
    }
  }
}

void Piece::calculateHorizontalPossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves){
  int file = getFileInt(source_square);
  int rank = getRankInt(source_square);

  bool is_white = board[rank][file]->isWhite();
  // Check horizontal lines to the right
  for(int f = file+1; f <= FILE_H; f++){
    if(!isDestinationEmpty(rank, f, is_white, board, possible_moves)){
      break;
    }
  }
  // Check horizontal lines to the left
  for(int f = file-1; f >= FILE_A; f--){
    if(!isDestinationEmpty(rank, f, is_white, board, possible_moves)){
      break;
    }
  }
}

void Piece::calculateDiagonalPossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves){
  int file = getFileInt(source_square);
  int rank = getRankInt(source_square);
  bool is_white = board[rank][file]->isWhite();
  // Check giagonal lines
  int r = rank+1;
  for(int f = file+1; f <= FILE_H; f++){
    if(!isDestinationEmpty(r, f, is_white, board, possible_moves)){
      break;
    }
    r++;
  }

  r = rank-1;
  for(int f = file+1; f <= FILE_H; f++){
    if(!isDestinationEmpty(r, f, is_white, board, possible_moves)){
      break;
    }
    r--;
  }

  r = rank+1;
  for(int f = file-1; f >= FILE_A; f--){
    if(!isDestinationEmpty(r, f, is_white, board, possible_moves)){
      break;
    }
    r++;
  }
  // Reset r
  r = rank-1;
  for(int f = file-1; f >= FILE_A; f--){
    if(!isDestinationEmpty(r, f, is_white, board, possible_moves)){
      break;
    }
    r--;
  }
}
