#include "ChessBoard.h"
#include "Definitions.h"

#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

ChessBoard::ChessBoard(){

  resetBoard();
}

void ChessBoard::submitMove(const char* source_square, const char* destination_square){

  // Check if the source square (A-H and 1-8) is valid or not
  int source_input_length = strlen(source_square);
  if(source_input_length != 2){
    cerr << "source input is not valid" << endl;
    return;
  }


  if(source_square[0] < 'A' || source_square[0] > 'H'){
    cerr << "not a valid file" << endl;
    return;
  }

  if(source_square[1] < '1' || source_square[1] > '8'){
    cerr << "not a valid rank" << endl;
    return;
  }

  // Check the piece in the square (exist? and match with current turn?)
// cout

  // Check which turn, (white or black?)

  // Check the destination square is valid
  // int destination_input_length = strlen(destination_square);
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
  int square = A1;
  int counter = 0;

  for(int i = 0; i < BOARD_SQUARE_SIZE; i++){
    square_120[i] = 65;
  }

  for(int i = 0; i < 64; i++){
    square_64[i] = 120;
    // square_64[i] = 12cl0;
  }

  for(int rank = rank_1; rank < rank_none; rank++){
    for(int file = file_a; file < file_none; file++){
      square = get_120_square_version(file, rank);
      square_120[square] = counter;
      square_64[counter] = square;
      counter++;
    }
  }

}

// TODO Delete this later
void ChessBoard::printBoard(){

  for(int i = 0; i < BOARD_SQUARE_SIZE; i++){
    if(i%10 == 0){
      cout << endl;
    }
    cout << setw(2) << setfill('0') << square_120[i] << " ";
  }
  cout << endl;
  cout << endl;

  for(int i = 0; i < 64; i++){
    if(i%8 == 0){
      cout << endl;
    }
    cout << square_64[i] << " ";
  }
}

void ChessBoard::printBitBoard(bit_64 bit_board){
  int square_120 = 0;
  int sq_64 = 0;
  bit_64 shift = 1ULL; // unsigned long long
  cout << endl;
  for(int rank = rank_8; rank >= rank_1; rank--){
    for(int file = file_a; file <= file_h; file++){
      square_120 = get_120_square_version(file, rank);
      sq_64 = square_64[square_120];
      // If bit_board is non-zero
      // & (not &&) does bitwise and operation
      if((shift << sq_64 & bit_board)){
        cout << "x ";
      }else{
        cout << "- ";
      }
    }
    cout << endl;
  }
  cout << endl;
}
