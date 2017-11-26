#include "ChessBoard.h"
#include "Pawn.h"
// #include "Queen.h"
// #include "King.h"
// #include "Rook.h"
// #include "Bishop.h"
// #include "Knight.h"

#include "Definitions.h"

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

using namespace std;

ChessBoard::ChessBoard(){
  // This is not starting from 0 (is this okay??)

  // Should I store object, or pointer??
  piece_map_[W_pawn] = new Pawn();
  // piece_map_[W_rook] = new Rook();
  // piece_map_[W_knight] = new Knight();
  // piece_map_[W_bishop] = new Bishop();
  // piece_map_[W_queen] = new Queen();
  // piece_map_[W_king] = new King();

  piece_map_[B_pawn] = new Pawn();
  // piece_map_[B_rook] = new Rook();
  // piece_map_[B_knight] = new Knight();
  // piece_map_[B_bishop] = new Bishop();
  // piece_map_[B_queen] = new Queen();
  // piece_map_[B_king] = new King();

  // TODO Don't forget to delete them!!

  is_white_turn_ = true;
  resetBoard();
  printCurrentBoard();
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

  // Check which turn, (white or black?)

  // Check the destination square is valid
  int destination_input_length = strlen(destination_square);
  if(destination_input_length != 2){
    cerr << "destination input is not valid" << endl;
    return;
  }

  if(destination_square[0] < 'A' || destination_square[0] > 'H'){
    cerr << "not a valid file" << endl;
    return;
  }

  if(destination_square[1] < '1' || destination_square[1] > '8'){
    cerr << "not a valid rank" << endl;
    return;
  }

  int piece = getPieceFromBoard(source_square);
  // Dynamic

  // Check the piece and check the restriction for the piece

  // Check if the move destroys an opponent piece
  cout << "piece " << piece << endl;
  // ?????
  // Piece p* = piece_map_[piece];

  // Change turn
  // (is_white_turn) ? is_white_turn = false : is_white_turn = true;

  make_move(source_square, destination_square);

  // Display the message
}

int ChessBoard::getPieceFromBoard(const char* source_square){
  int rank = source_square[1] - '1';
  int file = source_square[0] - 'A';
  return board_[rank][file];
}

// Getter for is_white_turn
bool ChessBoard::isWhiteTurn(){
  return is_white_turn_;
}

void ChessBoard::make_move(const char* source_square, const char* destination_square){
  int source_file = source_square[0] - 'A';
  int source_rank = source_square[1] - '1';
  int source_piece = board_[source_rank][source_file];
  board_[source_rank][source_file] = EMPTY;

  int dest_file = destination_square[0] - 'A';
  int dest_rank = destination_square[1] - '1';
  board_[dest_rank][dest_file] = source_piece;
  printCurrentBoard();
}

void ChessBoard::resetBoard(){
  for(int file = FILE_A; file < FILE_NONE; file++){
    board_[RANK_7][file] = B_pawn;
    board_[RANK_2][file] = W_pawn;
  }
  for(int rank = RANK_3; rank <= RANK_6; rank++){
    for(int file = FILE_A; file < FILE_NONE; file++){
      board_[rank][file] = EMPTY;
    }
  }

  board_[RANK_8][FILE_A] = B_rook;
  board_[RANK_8][FILE_B] = B_knight;
  board_[RANK_8][FILE_C] = B_bishop;
  board_[RANK_8][FILE_D] = B_queen;
  board_[RANK_8][FILE_E] = B_king;
  board_[RANK_8][FILE_F] = B_bishop;
  board_[RANK_8][FILE_G] = B_knight;
  board_[RANK_8][FILE_H] = B_rook;

  board_[RANK_1][FILE_A] = W_rook;
  board_[RANK_1][FILE_B] = W_knight;
  board_[RANK_1][FILE_C] = W_bishop;
  board_[RANK_1][FILE_D] = W_queen;
  board_[RANK_1][FILE_E] = W_king;
  board_[RANK_1][FILE_F] = W_bishop;
  board_[RANK_1][FILE_G] = W_knight;
  board_[RANK_1][FILE_H] = W_rook;
}

void ChessBoard::printCurrentBoard(){
  cout << "========================" << endl;
    for(int rank = RANK_8; rank >= RANK_1; rank--){
      cout << endl;
      for(int file = FILE_A; file < FILE_NONE; file++){
        cout << convertIntToPiece(board_[rank][file]) << " ";
      }
    }
    cout << endl;
    cout << "========================" << endl;
}

string ChessBoard::convertIntToPiece(int& num){
  switch(num){
    case(EMPTY): return "--"; break;
    case(W_pawn): return "WP"; break;
    case(W_rook): return "WR"; break;
    case(W_knight): return "WN"; break;
    case(W_bishop): return "WB"; break;
    case(W_queen): return "WQ"; break;
    case(W_king): return "WK"; break;
    case(B_pawn): return "BP"; break;
    case(B_rook): return "BR"; break;
    case(B_knight): return "BN"; break;
    case(B_bishop): return "BB"; break;
    case(B_queen): return "BQ"; break;
    case(B_king): return "BK"; break;
  }
  // TODO default value
}
