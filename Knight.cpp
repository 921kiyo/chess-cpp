#include "Helper.h"
#include "Piece.h"
#include "Knight.h"

#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

Knight::Knight(bool white):Piece(white){}

void Knight::calculatePossibleMove(const string source_square, \
                                   shared_ptr<Piece> board[][BOARD_LENGTH],
                                   vector<string>& possible_moves){
  calculateLShapePossibleMove(source_square, board, possible_moves);
}

void Knight::calculateLShapePossibleMove(const string source_square, \
                                      shared_ptr<Piece> board[][BOARD_LENGTH], \
                                      vector<string>& possible_moves){
  int rank = getRankInt(source_square);
  int file = getFileInt(source_square);
  bool is_white = board[rank][file]->isWhite();
  string sq;
  // Loop through all squares two squares away from the knight's position
  for(int f = file -2; f <= file + 2; f++){
    if(f >= FILE_A && f <= FILE_H){
      for(int r = rank -2; r <= rank + 2; r++){
        if(r >= RANK_1 && r <= RANK_8){
          // If the following squares are empty or has opponent's piece,
          // then the knight can move
          // 1. A square that is two squares away horizontally and
          // one square vertically
          // 2. A square that is two squares away vertically and
          // one square horizontally
          if(((abs(f - file) == 2) && (abs(r - rank) == 1)) || \
             ((abs(f - file) == 1) && (abs(r - rank) == 2))){
            if(board[r][f] == nullptr || \
              (board[r][f] != nullptr && \
              (is_white != board[r][f]->isWhite()))){
              sq = getStringSquare(f, r);
              possible_moves.push_back(sq);
            }
          }
        }
      }
    }
  }
}

string Knight::getString(){
  return (is_white_)? "White's Knight": "Black's Knight";
}

string Knight::getSimbol(){
  return (is_white_)? "WN": "BN";
}
