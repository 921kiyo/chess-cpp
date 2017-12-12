#include "Helper.h"
#include "Piece.h"

#include <iostream>
#include <string>
#include <memory>
using namespace std;

Piece::Piece(bool white): is_white_(white), is_first_move_(true){}

bool Piece::isValidMove(const string source_square, \
                        const string destination_square, \
                        shared_ptr<Piece> board[][BOARD_LENGTH]){
  vector<string> possible_moves;

  calculatePossibleMove(source_square, board, possible_moves);

  for(string square: possible_moves){
    if(destination_square == square){
      return true;
    }
  }
  return false;
}

bool Piece::canMoveForward(int rank, int file, bool is_white, \
                               shared_ptr<Piece> board[][BOARD_LENGTH], \
                               vector<string>& possible_moves){
  string sq;
  // Check if either rank or file is off the board
  if(rank < RANK_1 || rank > RANK_8 || file < FILE_A || file > FILE_H){
    return false;
  }

  // Check if there is a piece of the same color along the way
  if(board[rank][file] != nullptr && is_white == board[rank][file]->isWhite()){
    return false;
  }
  // If ther is a piece of difference color along the way, the piece has to
  // stop after it capture the opponent piece (cannot move further)
  else if(board[rank][file] != nullptr && \
          is_white != board[rank][file]->isWhite()){
    sq = getStringSquare(file, rank);
    possible_moves.push_back(sq);
    return false;
  }
  // If there is no piece, it can continue to move forward
  else if(board[rank][file] == nullptr){
     sq = getStringSquare(file, rank);
     possible_moves.push_back(sq);
     return true;
  }
  return false;
}

void Piece::calculateVerticalPossibleMove(const string source_square, \
                                      shared_ptr<Piece> board[][BOARD_LENGTH], \
                                          vector<string>& possible_moves){
  int file = getFileInt(source_square);
  int rank = getRankInt(source_square);
  bool is_white = board[rank][file]->isWhite();
  // Check vertical lines to the top
  for(int r = rank+1; r <= RANK_8; r++){
    if(!canMoveForward(r, file, is_white, board, possible_moves)){
      break;
    }
  }
  // Check vertical line to the bottom
  for(int r = rank-1; r >= RANK_1; r--){
    if(!canMoveForward(r, file, is_white, board, possible_moves)){
      break;
    }
  }
}

void Piece::calculateHorizontalPossibleMove(const string source_square, \
                                      shared_ptr<Piece> board[][BOARD_LENGTH], \
                                      vector<string>& possible_moves){
  int file = getFileInt(source_square);
  int rank = getRankInt(source_square);

  bool is_white = board[rank][file]->isWhite();
  // Check horizontal lines to the right
  for(int f = file+1; f <= FILE_H; f++){
    if(!canMoveForward(rank, f, is_white, board, possible_moves)){
      break;
    }
  }
  // Check horizontal lines to the left
  for(int f = file-1; f >= FILE_A; f--){
    if(!canMoveForward(rank, f, is_white, board, possible_moves)){
      break;
    }
  }
}

void Piece::calculateDiagonalPossibleMove(const string source_square, \
                                      shared_ptr<Piece> board[][BOARD_LENGTH], \
                                      vector<string>& possible_moves){
  int file = getFileInt(source_square);
  int rank = getRankInt(source_square);
  bool is_white = board[rank][file]->isWhite();
  // Check giagonal lines (north east)
  int r = rank+1;
  for(int f = file+1; f <= FILE_H; f++){
    if(!canMoveForward(r, f, is_white, board, possible_moves)){
      break;
    }
    r++;
  }

  // Check giagonal lines (south east)
  r = rank-1;
  for(int f = file+1; f <= FILE_H; f++){
    if(!canMoveForward(r, f, is_white, board, possible_moves)){
      break;
    }
    r--;
  }

  // Check giagonal lines (north west)
  r = rank+1;
  for(int f = file-1; f >= FILE_A; f--){
    if(!canMoveForward(r, f, is_white, board, possible_moves)){
      break;
    }
    r++;
  }

  // Check giagonal lines (south west)
  r = rank-1;
  for(int f = file-1; f >= FILE_A; f--){
    if(!canMoveForward(r, f, is_white, board, possible_moves)){
      break;
    }
    r--;
  }
}

bool Piece::isWhite(){
  return is_white_;
}

bool Piece::isFirstMove(){
  return is_first_move_;
}

void Piece::negateIsFirstMove(){
  if(is_first_move_){
    is_first_move_ = false;
  }
}
