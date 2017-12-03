
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

string Knight::getSimbol(){
  if(is_white_){
    return "WN";
  }
  else{
    return "BN";
  }
}
