
#include "King.h"
#include "Piece.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

King::King(bool white):Piece(white){}

King::~King(){}

string King::getSimbol(){
  if(is_white_){
    return "WK";
  }
  else{
    return "BK";
  }
}

void King::calculatePossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves){
  int rank = source_square.at(1) - '1';
  int file = source_square.at(0) - 'A';
  char square[3];
  string sq;
  for(int f = file-1; f <= file+1; f++){
    for(int r = rank-1; r <= rank+1; r++){
      cout << "file " << f << endl;
      cout << "rank " << r << endl;
      // not the same as source_square
      if(f != file || r != rank){
        if(r <= RANK_8 && r >= RANK_1 && f <= FILE_H && f >= FILE_A){
            // If the square is empty or piece of different color
            if((board[r][f] == NULL) || (board[r][f] != NULL && board[rank][file]->getIsWhite() != board[r][f]->getIsWhite())){
              square[0] = f + 'A';
              square[1] = r + '1';
              square[2] = '\0';
              sq = square;
              possible_moves.push_back(sq);
              cout << "square " << square << endl;
            }
            // cout << "===========" << endl;
            // cout << "file " << f << endl;
            // cout << "rank " << r << endl;
        }
      }
    }
  }
  //   // If the king is at a corner, you cannot go beoynd the board
}

// bool King::isKingSafe(){
//   return true;
// }
