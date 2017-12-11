
#include "King.h"
#include "Piece.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

King::King(bool white):Piece(white){}

King::~King(){}

void King::calculatePossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves){
  calculateAdjacentPossibleMove(source_square, board, possible_moves);
}

void King::calculateAdjacentPossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves){
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

string King::getString(){
  return (is_white_)? "White's King": "Black's King";
}

string King::getSimbol(){
  return (is_white_)? "WK": "BK";
}
