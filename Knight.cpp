
#include "Knight.h"
#include "Piece.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Knight::~Knight(){}

Knight::Knight(bool white):Piece(white){}
bool Knight::isValidMove(){
  return true;
}

void Knight::calculatePossibleMove(int rank, int file, int board){

}

string Knight::getSimbol(){
  if(is_white_){
    return "WN";
  }
  else{
    return "BN";
  }
}
