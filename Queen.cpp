#include "Queen.h"
#include "Piece.h"
#include "Definitions.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Queen::Queen(bool white): Piece(white){
}

Queen::~Queen(){}

void Queen::calculatePossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves){
  calculateVerticalPossibleMove(source_square, board, possible_moves);
  calculateHorizontalPossibleMove(source_square, board, possible_moves);
  calculateDiagonalPossibleMove(source_square, board, possible_moves);
}

bool Queen::checkSquare(int rank, int file, bool is_white, Piece* board[8][8], vector<string>& possible_moves){
  char square[3];
  string sq;
  if(rank < RANK_1 || rank > RANK_8 || file < FILE_A || file > FILE_H){
    return false;
  }
  if(board[rank][file] != NULL && is_white == board[rank][file]->getIsWhite()){
    return false;
  }
  else if(board[rank][file] != NULL && is_white != board[rank][file]->getIsWhite()){
    square[0] = file + 'A';
    square[1] = rank + '1';
    square[2] = '\0';
    sq = square;
    possible_moves.push_back(sq);
    cout << "square " << square << endl;
    return false;
  }
  else if(board[rank][file] == NULL){
     square[0] = file + 'A';
     square[1] = rank + '1';
     square[2] = '\0';
     sq = square;
     possible_moves.push_back(sq);
     cout << "square " << square << endl;
     return true;
  }
}

void Queen::calculateVerticalPossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves){
  int rank = source_square.at(1) - '1';
  int file = source_square.at(0) - 'A';
  bool is_white = board[rank][file]->getIsWhite();
  // Check vertical lines to the top
  for(int r = rank+1; r <= RANK_8; r++){
    if(!checkSquare(r, file, is_white, board, possible_moves)){
      break;
    }
  }
  // Check vertical line to the bottom
  for(int r = rank-1; r >= RANK_1; r--){
    if(!checkSquare(r, file, is_white, board, possible_moves)){
      break;
    }
  }
}

void Queen::calculateHorizontalPossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves){
  int rank = source_square.at(1) - '1';
  int file = source_square.at(0) - 'A';
  bool is_white = board[rank][file]->getIsWhite();
  // Check horizontal lines to the right
  for(int f = file+1; f <= FILE_H; f++){
    if(!checkSquare(rank, f, is_white, board, possible_moves)){
      break;
    }
  }
  // Check horizontal lines to the left
  for(int f = file-1; f >= FILE_A; f--){
    if(!checkSquare(rank, f, is_white, board, possible_moves)){
      break;
    }
  }
}

void Queen::calculateDiagonalPossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves){
  int rank = source_square.at(1) - '1';
  int file = source_square.at(0) - 'A';
  bool is_white = board[rank][file]->getIsWhite();
  // Check giagonal lines
  int r = rank+1;
  for(int f = file+1; f <= FILE_H; f++){
    if(!checkSquare(r, f, is_white, board, possible_moves)){
      break;
    }
    r++;
  }

  r = rank-1;
  for(int f = file+1; f <= FILE_H; f++){
    if(!checkSquare(r, f, is_white, board, possible_moves)){
      break;
    }
    r--;
  }

  r = rank+1;
  for(int f = file-1; f >= FILE_A; f--){
    if(!checkSquare(r, f, is_white, board, possible_moves)){
      break;
    }
    r++;
  }
  // Reset r
  r = rank-1;
  for(int f = file-1; f >= FILE_A; f--){
    if(!checkSquare(r, f, is_white, board, possible_moves)){
      break;
    }
    r--;
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
