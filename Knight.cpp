
#include "Knight.h"
#include "Piece.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Knight::~Knight(){}

Knight::Knight(bool white):Piece(white){}

void Knight::calculatePossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves){
  calculateLShapePossibleMove(source_square, board, possible_moves);
}

void Knight::calculateLShapePossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves){
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
            if(board[r][f] == NULL || (is_white != board[r][f]->isWhite())){
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


string Knight::getSimbol(){
  if(is_white_){
    return "WN";
  }
  else{
    return "BN";
  }
}
