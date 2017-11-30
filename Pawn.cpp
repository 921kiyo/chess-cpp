
#include "Pawn.h"
#include "Piece.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
Pawn::Pawn(bool white): Piece(white){}
bool Pawn::isValidMove(){
  return true;
}

// void Pawn::calculatePossibleMove(int rank, int file, int board){
//
// }

string Pawn::getSimbol(){
  if(is_white_){
    return "WR";
  }
  else{
    return "BR";
  }
}
