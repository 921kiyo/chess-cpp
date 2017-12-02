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

// bool Queen::isValidMove(){
//
// }
void Queen::calculatePossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves){
  int rank = source_square.at(1) - '1';
  int file = source_square.at(0) - 'A';

  char square[3];
  string sq;
  // Check vertical lines to the top
  for(int r = rank+1; r <= RANK_8; r++){
    if(board[r][file] != NULL && board[rank][file]->getIsWhite() != board[r][file]->getIsWhite()){
      break;
    }
    else if(board[r][file] == NULL){
       square[0] = r + '1';
       square[1] = source_square.at(0);
       square[2] = '\0';
       sq = square;
       possible_moves.push_back(sq);
       cout << "square1 " << square << endl;
    }

  }
  // Check vertical line to the bottom
  for(int r = rank-1; r >= RANK_1; r--){
    if(board[r][file] != NULL && board[rank][file]->getIsWhite() != board[r][file]->getIsWhite()){
      break;
    }
    else if(board[r][file] == NULL){
      square[0] = r + '1';
      square[1] = source_square.at(0);
      square[2] = '\0';
      sq = square;
      possible_moves.push_back(sq);
      cout << "square2 " << square << endl;
    }
  }

  // Check horizontal lines to the right
  for(int f = file+1; f <= FILE_H; f++){
    if(board[rank][f] != NULL && board[rank][f]->getIsWhite() != board[rank][f]->getIsWhite()){
      break;
    }
    else if(board[rank][f] == NULL){
      square[0] = source_square.at(1);
      square[1] = f + 'A';
      square[2] = '\0';
      sq = square;
      possible_moves.push_back(sq);
      cout << "square3 " << square << endl;
    }
  }

  // Check horizontal lines to the right
  for(int f = file-1; f >= FILE_A; f--){
    if(board[rank][f] != NULL && board[rank][f]->getIsWhite() != board[rank][f]->getIsWhite()){
      break;
    }
    else if(board[rank][f] == NULL){
      square[0] = source_square.at(1);
      square[1] = f + 'A';
      square[2] = '\0';
      sq = square;
      possible_moves.push_back(sq);
      cout << "square3 " << square << endl;
    }
  }
  // Check giagonal lines

  // for(int f = file+1; f <= FILE_H; f++){
  //
  //
  // }

  // If it captures an opponent's piece, then it has to stop there.
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
