#include "ChessBoard.h"
#include "Pawn.h"
#include "Queen.h"
#include "King.h"
#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"

#include "Definitions.h"

#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include <vector>
#include <iomanip>

using namespace std;

ChessBoard::ChessBoard(){
  is_white_in_check_ = false;
  is_black_in_check_ = false;
  // I do not need to create all pawn
  for(int file = FILE_A; file < FILE_NONE; file++){
    // board_[RANK_7][file] = new Pawn(false);
    // board_[RANK_2][file] = new Pawn(true);
    board_[RANK_7][file] = nullptr;
    board_[RANK_2][file] = nullptr;
  }
  for(int rank = RANK_3; rank <= RANK_6; rank++){
    for(int file = FILE_A; file < FILE_NONE; file++){
      board_[rank][file] = nullptr;
    }
  }

  board_[RANK_8][FILE_A] = nullptr;
  board_[RANK_8][FILE_B] = nullptr;
  board_[RANK_8][FILE_C] = nullptr;
  board_[RANK_8][FILE_D] = nullptr;
  board_[RANK_8][FILE_E] = nullptr;
  board_[RANK_8][FILE_F] = nullptr;
  board_[RANK_8][FILE_G] = nullptr;
  board_[RANK_8][FILE_H] = nullptr;

  board_[RANK_1][FILE_A] = nullptr;
  board_[RANK_1][FILE_B] = nullptr;
  board_[RANK_1][FILE_C] = nullptr;
  board_[RANK_1][FILE_D] = nullptr;
  board_[RANK_1][FILE_E] = nullptr;
  board_[RANK_1][FILE_F] = nullptr;
  board_[RANK_1][FILE_G] = nullptr;
  board_[RANK_1][FILE_H] = nullptr;

  // board_[RANK_1][FILE_E] = new Queen(false);
  char king_position[3];
  board_[RANK_5][FILE_D] = new Knight(false);

  // board_[RANK_3][FILE_B] = new Pawn(false);

  board_[RANK_4][FILE_D] = new King(false);
  king_position[0] = FILE_D + 'A';
  king_position[1] = RANK_4 + '1';
  king_position[2] = '\0';
  black_king_position_ = king_position;
  // board_[RANK_5][FILE_B] = new Knight(true);
  board_[RANK_1][FILE_A] = new King(true);
  king_position[0] = FILE_A + 'A';
  king_position[1] = RANK_1 + '1';
  king_position[2] = '\0';
  white_king_position_ = king_position;
  board_[RANK_2][FILE_A] = new Pawn(false);

  // board_[RANK_8][FILE_H] = new King(false);

  // board_[RANK_8][FILE_A] = new Rook(false);
  // board_[RANK_8][FILE_B] = new Knight(false);
  // board_[RANK_8][FILE_C] = new Bishop(false);
  // board_[RANK_8][FILE_D] = new Queen(false);
  // board_[RANK_8][FILE_E] = new King(false);
  // board_[RANK_8][FILE_F] = new Bishop(false);
  // board_[RANK_8][FILE_G] = new Knight(false);
  // board_[RANK_8][FILE_H] = new Rook(false);
  //
  // board_[RANK_1][FILE_A] = new Rook(true);
  // board_[RANK_1][FILE_B] = new Knight(true);
  // board_[RANK_1][FILE_C] = new Bishop(true);
  // board_[RANK_1][FILE_D] = new Queen(true);
  // board_[RANK_1][FILE_E] = new King(true);
  // board_[RANK_1][FILE_F] = new Bishop(true);
  // board_[RANK_1][FILE_G] = new Knight(true);
  // board_[RANK_1][FILE_H] = new Rook(true);

  is_white_turn_ = true;
  printCurrentBoard();
}

ChessBoard::~ChessBoard(){
  // TODO Double check memory leak
  // for(int i = W_pawn; i <= B_king; i++){
  //   delete piece_map_[i];
  // }
}

void ChessBoard::submitMove(const string source_square, const string destination_square){
  // Check if the source square (A-H and 1-8) is valid or not
  int source_input_length = source_square.length();
  if(source_input_length != 2){
    cerr << "source input is not valid" << endl;
    return;
  }

  if(source_square.at(0) < 'A' || source_square.at(0) > 'H'){
    cerr << "not a valid file" << endl;
    return;
  }

  if(source_square.at(1) < '1' || source_square.at(1) > '8'){
    cerr << "not a valid rank" << endl;
    return;
  }

  // Check the destination square is valid
  int destination_input_length = destination_square.length();
  if(destination_input_length != 2){
    cerr << "destination input is not valid" << endl;
    return;
  }

  if(destination_square.at(0) < 'A' || destination_square.at(0) > 'H'){
    cerr << "not a valid file" << endl;
    return;
  }

  if(destination_square.at(1) < '1' || destination_square.at(1) > '8'){
    cerr << "not a valid rank" << endl;
    return;
  }

  Piece* piece = getPieceFromBoard(source_square);
  // TODO Fix the error message when there is a piece in front of a pawn
  if(piece == nullptr){
    cerr << "There is no piece in the square you selected" << endl;
    return;
  }

  // Check the piece in the square (exist? and match with current turn?)
  // Check which turn, (white or black?)
  if(!is_white_turn_  && piece->getIsWhite()){
    cerr << "It is black turn, and cannot move a white piece" << endl;
    return;
  }
  if(is_white_turn_  && !piece->getIsWhite()){
    cerr << "It is white turn, and cannot move a black piece" << endl;
    return;
  }

  vector<string> possible_moves;
  cout << "white check? " << is_white_in_check_ << endl;
  if(is_white_turn_ && is_white_in_check_){
    calculatePossibleMoveToSaveKing(possible_moves);
    // After moves, check if the king is still safe
  }
  if(!is_white_turn_ && is_black_in_check_){
    calculatePossibleMoveToSaveKing(possible_moves);
  }

  for(string move: possible_moves){
    cout << "move: " << move << endl;
  }

  possible_moves.clear();

  // Check if the move destroys an opponent piece

  if(piece->isValidMove(source_square, destination_square, board_)){
    makeMove(source_square, destination_square);
  }
  // Display the message

  // Update current player (white and black)
  (is_white_turn_) ? is_white_turn_ = false : is_white_turn_ = true;
}

Piece* ChessBoard::getPieceFromBoard(const string source_square){
  int rank = source_square.at(1) - '1';
  int file = source_square.at(0) - 'A';
  return board_[rank][file];
}

// Actually, this can also work for other pieces
void ChessBoard::getKingPosition(const int king_enum, char* king_position){
  // for(int rank = RANK_1; rank <  RANK_NONE; rank++){
  //   for(int file = FILE_A; file < FILE_NONE; file++){
  //     if(board_[rank][file] == king_enum){
  //       king_position[0] = file + 'A';
  //       king_position[1] = rank + '1';
  //       king_position[2] = '\0';
  //     }
  //   }
  // }
  // return -1;
}

// Getter for is_white_turn
bool ChessBoard::isWhiteTurn(){
  return is_white_turn_;
}

// TODO Delete these setters
void ChessBoard::updateWhiteKingPtr(Piece* wk){
  white_king_ = wk;
}

void ChessBoard::updateBlackKingPtr(Piece* bk){
  white_king_ = bk;
}

void ChessBoard::updateWhiteKingPosition(string wk){
  white_king_position_ = wk;
}

void ChessBoard::updateBlackKingPosition(string bk){
  black_king_position_ = bk;
}

// TODO it is now memory leaking
void ChessBoard::makeMove(string source_square, string destination_square){
  int source_file = source_square.at(0) - 'A';
  int source_rank = source_square.at(1) - '1';
  Piece* source_piece = board_[source_rank][source_file];

  int dest_file = destination_square.at(0) - 'A';
  int dest_rank = destination_square.at(1) - '1';
  board_[dest_rank][dest_file] = source_piece;
  board_[source_rank][source_file] = nullptr;

  if(source_piece->getSimbol() == "WK"){
    white_king_ = source_piece;
    white_king_position_ = destination_square;
  }
  else if(source_piece->getSimbol() == "BK"){
    black_king_ = source_piece;
    black_king_position_ = destination_square;
  }

  if(is_white_turn_){
    // TODO Use access function
    if(!white_king_->isKingSafe(white_king_position_, board_)){
      cerr << "The move makes your king in check, therefore invalid move" << endl;
      // Undo the move
    }
    if(!black_king_->isKingSafe(black_king_position_, board_)){
      cout << "back king is now in check!!" << endl;
      is_black_in_check_ = true;
    }
  }else{

    if(!black_king_->isKingSafe(black_king_position_, board_)){
      cerr << "The move makes your king in check, therefore invalid move" << endl;
      // Should this stop the program?
    }
    if(!white_king_->isKingSafe(white_king_position_, board_)){
      cout << "white king is now in check!!" << endl;
      is_white_in_check_ = true;
    }
  }

  source_piece->negateIsFirstMove();
  cout << "move complete " << endl;
  printCurrentBoard();
}

void ChessBoard::calculatePossibleMoveToSaveKing(vector<string>&possible_moves){
  string sq;
  char source_square[3];
  for(int rank = RANK_1; rank <= RANK_8; rank++){
    for(int file = FILE_A; file <= FILE_H; file){
      source_square[0] = file;
      source_square[1] = rank;
      source_square[2] = '\0';
      sq = source_square;
      cout << "sq " << sq << endl;
      // Check opponent black pieces
      if(is_white_turn_ && board_[rank][file] != nullptr && board_[rank][file]->getIsWhite()){
        board_[rank][file]->calculatePossibleMove(sq, board_, possible_moves);
      }
      // Check opponent white pieces
      if(!is_white_turn_ && board_[rank][file] != nullptr && !board_[rank][file]->getIsWhite()){
        board_[rank][file]->calculatePossibleMove(sq, board_, possible_moves);
      }
    }
  }
}

void ChessBoard::resetBoard(){

}

void ChessBoard::printCurrentBoard(){
  cout << "========================" << endl;
    for(int rank = RANK_8; rank >= RANK_1; rank--){
      cout << endl;
      for(int file = FILE_A; file < FILE_NONE; file++){
        if(board_[rank][file] == nullptr){
          cout << "-- ";
        }
        else{
          cout << board_[rank][file]->getSimbol() << " ";
        }
      }
    }
    cout << endl;
    cout << "========================" << endl;
}
