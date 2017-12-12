#include "Helper.h"
#include "Piece.h"
#include "King.h"

#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

King::King(bool white):Piece(white){}

void King::calculatePossibleMove(const string source_square, \
                                 shared_ptr<Piece> board[][BOARD_LENGTH], \
                                 vector<string>& possible_moves){
  calculateAdjacentPossibleMove(source_square, board, possible_moves);
}

void King::calculateAdjacentPossibleMove(const string source_square, \
                                      shared_ptr<Piece> board[][BOARD_LENGTH], \
                                      vector<string>& possible_moves){

  int file = getFileInt(source_square);
  int rank = getRankInt(source_square);
  string sq;
  for(int f = file-1; f <= file+1; f++){
    for(int r = rank-1; r <= rank+1; r++){
      // not the same as source_square
      if(f != file || r != rank){
        if(r <= RANK_8 && r >= RANK_1 && f <= FILE_H && f >= FILE_A){
            // If the square is empty or piece of different color
            if((board[r][f] == nullptr) || (board[r][f] != nullptr && \
                board[rank][file]->isWhite() != board[r][f]->isWhite())){
              sq = getStringSquare(f, r);
              possible_moves.push_back(sq);
            }
        }
      }
    }
  }
}

string King::getString(){
  return (is_white_)? "White's King": "Black's King";
}

string King::getSimbol(){
  return (is_white_)? "WK": "BK";
}
