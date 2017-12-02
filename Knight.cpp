
#include "Knight.h"
#include "Piece.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Knight::~Knight(){}

Knight::Knight(bool white):Piece(white){}
// bool Knight::isValidMove(){
//   return true;
// }

void Knight::calculatePossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves){
  int rank = source_square.at(1) - '1';
  int file = source_square.at(0) - 'A';
  bool is_white = board[rank][file]->getIsWhite();
  char square[3];
  string sq;
  for(int f = file -2; f <= file + 2; f++){
    for(int r = rank -2; r <= rank + 2; r++){
      if(((abs(f - file) == 2) && (abs(r - rank) == 1)) || ((abs(f - file) == 1) && (abs(r - rank) == 2))){
        if(board[r][f] == NULL || (board[r][f] == NULL && is_white != board[r][f]->getIsWhite())){
          square[0] = f + 'A';
          square[1] = r + '1';
          square[2] = '\0';
          sq = square;
          possible_moves.push_back(sq);
          // cout << "square " << sq << endl;
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
