#include "Bishop.h"

#include <iostream>
#include <string>
using namespace std;

Bishop::Bishop(bool white):Piece(white){

}
Bishop::~Bishop(){}


bool Bishop::isValidMove(){

}

string Bishop::getSimbol(){
  if(is_white_){
    return "WB";
  }
  else{
    return "BB";
  }
}
