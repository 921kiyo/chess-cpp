#include "ChessBoard.h"

#include <iostream>
#include <cstring>

using namespace std;

ChessBoard::ChessBoard(){
  is_white_turn = true;
}

void ChessBoard::submitMove(const char* source_square, const char* destination_square){

  // Check if the source square (A-H and 1-8) is valid or not
  int source_input_length = strlen(source_square);
  if(source_input_length != 2){
    cerr << "source input is not valid" << endl;
    return;
  }

  cout << "source " << source_square[0] << endl;

  // Check the piece in the square (exist? and match with current turn?)


  // Check which turn, (white or black?)

  // Check the destination square is valid
  int destination_input_length = strlen(destination_square);
  // Check the piece and check the restriction for the piece


  // Check if the move destroys an opponent piece

  // Change turn
  // (is_white_turn) ? is_white_turn = false : is_white_turn = true;

  // Display the message
}

// Getter for is_white_turn
bool ChessBoard::isWhiteTurn(){
  return is_white_turn;
}

void ChessBoard::resetBoard(){
  cout << "resetBoard" << endl;
}
