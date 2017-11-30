#include "Rook.h"
#include "Piece.h"

#include <iostream>
#include <string>
using namespace std;

Rook::Rook(bool white): Piece(white){
}

Rook::~Rook(){}

bool Rook::isValidMove(){

}

string Rook::getSimbol(){
  if(is_white_){
    return "WP";
  }
  else{
    return "BP";
  }
}
