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
    // cout << "sq " << square << endl;
    if(destination_square == square){
      // cout << "yes" << endl;
      return true;
    }

  }

  return false;

  // Check if the move makes the king in check.
  // isKingSafe()
}

bool Piece::isWhite(){
  return is_white_;
}

void Piece::negateIsFirstMove(){
  if(is_first_move_){
    is_first_move_ = false;
  }
}

bool Piece::checkSquare(int rank, int file, bool is_white, Piece* board[8][8], vector<string>& possible_moves){
  char square[3];
  string sq;
  if(rank < RANK_1 || rank > RANK_8 || file < FILE_A || file > FILE_H){
    return false;
  }
  if(board[rank][file] != NULL && is_white == board[rank][file]->isWhite()){
    return false;
  }
  else if(board[rank][file] != NULL && is_white != board[rank][file]->isWhite()){
    square[0] = file + 'A';
    square[1] = rank + '1';
    square[2] = '\0';
    sq = square;
    possible_moves.push_back(sq);
    return false;
  }
  else if(board[rank][file] == NULL){
     square[0] = file + 'A';
     square[1] = rank + '1';
     square[2] = '\0';
     sq = square;
     possible_moves.push_back(sq);
     return true;
  }
}

void Piece::calculateVerticalPossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves){
  int rank = source_square.at(1) - '1';
  int file = source_square.at(0) - 'A';
  bool is_white = board[rank][file]->isWhite();
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

void Piece::calculateHorizontalPossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves){
  int rank = source_square.at(1) - '1';
  int file = source_square.at(0) - 'A';
  bool is_white = board[rank][file]->isWhite();
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

void Piece::calculateDiagonalPossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves){
  int rank = source_square.at(1) - '1';
  int file = source_square.at(0) - 'A';
  bool is_white = board[rank][file]->isWhite();
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

void Piece::calculateAdjacentPossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves){
  int rank = source_square.at(1) - '1';
  int file = source_square.at(0) - 'A';
  char square[3];
  string sq;
  for(int f = file-1; f <= file+1; f++){
    for(int r = rank-1; r <= rank+1; r++){
      // not the same as source_square
      if(f != file || r != rank){
        if(r <= RANK_8 && r >= RANK_1 && f <= FILE_H && f >= FILE_A){
            // If the square is empty or piece of different color
            if((board[r][f] == NULL) || (board[r][f] != NULL && board[rank][file]->isWhite() != board[r][f]->isWhite())){
              square[0] = f + 'A';
              square[1] = r + '1';
              square[2] = '\0';
              sq = square;
              possible_moves.push_back(sq);
            }
        }
      }
    }
  }
}

void Piece::calculateLShapePossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves){
  int rank = source_square.at(1) - '1';
  int file = source_square.at(0) - 'A';
  bool is_white = board[rank][file]->isWhite();
  char square[3];
  string sq;
  for(int f = file -2; f <= file + 2; f++){
    if(f >= FILE_A && f <= FILE_H){
      for(int r = rank -2; r <= rank + 2; r++){
        if(r >= RANK_1 && r <= RANK_8){
          if(((abs(f - file) == 2) && (abs(r - rank) == 1)) || ((abs(f - file) == 1) && (abs(r - rank) == 2))){
            if(board[r][f] == NULL || (board[r][f] == NULL && is_white != board[r][f]->isWhite())){
              square[0] = f + 'A';
              square[1] = r + '1';
              square[2] = '\0';
              sq = square;
              possible_moves.push_back(sq);
            }
          }
        }
      }
    }
  }
}

void Piece::calculatePawnPossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves){
  int rank = source_square.at(1) - '1';
  int file = source_square.at(0) - 'A';
  bool is_white = board[rank][file]->isWhite();
  char square[3];
  string sq;
  // White pawn move forward up
  if(is_white && rank < RANK_8){
    if(is_first_move_ && (board[rank+1][file] == NULL) &&(board[rank+2][file] == NULL) ){
      square[0] = file  + 'A';
      square[1] = rank + 2 + '1';
      square[2] = '\0';
      sq = square;
      possible_moves.push_back(sq);
    }
    if(board[rank+1][file] == NULL){
      square[0] = file  + 'A';
      square[1] = rank + 1 + '1';
      square[2] = '\0';
      sq = square;
      possible_moves.push_back(sq);
    }

    // If there is a black piece in the diagonal forward
    if((file < FILE_H) && (board[rank+1][file+1] != NULL) && (!board[rank+1][file+1]->isWhite())){
      square[0] = file + 1  + 'A';
      square[1] = rank + 1 + '1';
      square[2] = '\0';
      sq = square;
      possible_moves.push_back(sq);
    }
    if((file > FILE_A) && (board[rank+1][file-1] != NULL) && !board[rank+1][file-1]->isWhite()){
      square[0] = file -1 + 'A';
      square[1] = rank + 1 + '1';
      square[2] = '\0';
      sq = square;
      possible_moves.push_back(sq);
    }
  }
  // Black pawn move forward down
  else if(!is_white && rank > RANK_1){
    if(is_first_move_ && (board[rank-1][file] == NULL) &&(board[rank-2][file] == NULL)){
      square[0] = file  + 'A';
      square[1] = rank - 2 + '1';
      square[2] = '\0';
      sq = square;
      possible_moves.push_back(sq);
    }
    if(board[rank-1][file] == NULL){
      square[0] = file  + 'A';
      square[1] = rank - 1 + '1';
      square[2] = '\0';
      sq = square;
      possible_moves.push_back(sq);
    }

    // If there is a white piece in the diagonal forward
    if((file > FILE_A) && (board[rank-1][file-1] != NULL) && (!board[rank-1][file-1]->isWhite())){
      square[0] = file - 1  + 'A';
      square[1] = rank - 1 + '1';
      square[2] = '\0';
      sq = square;
      possible_moves.push_back(sq);
    }
    if((file < FILE_H) && (board[rank-1][file+1] != NULL) && !board[rank-1][file+1]->isWhite()){
      square[0] = file +1 + 'A';
      square[1] = rank - 1 + '1';
      square[2] = '\0';
      sq = square;
      possible_moves.push_back(sq);
    }
  }
}
