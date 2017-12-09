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

// #include <memory>

using namespace std;

ChessBoard::ChessBoard(): black_pawn_(false), black_rook_(false), \
black_knight_(false), black_bishop_(false), black_queen_(false), \
black_king_(false), white_pawn_(true), white_rook_(true), white_knight_(true), \
white_bishop_(true), white_queen_(true), white_king_(true){

  is_white_in_check_ = false;
  is_black_in_check_ = false;

  // shared_ptr<Pawn> black_pawn_ptr = make_shared<Pawn>(false);

  for(int file = FILE_A; file < FILE_NONE; file++){
    board_[RANK_7][file] = &black_pawn_;
    // board_[RANK_2][file] = white_pawn;
    // board_[RANK_7][file] = nullptr;
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

  char king_position[3];
  board_[RANK_3][FILE_B] = &black_queen_;
  board_[RANK_1][FILE_A] = &white_king_;
  board_[RANK_1][FILE_B] = &white_pawn_;
  board_[RANK_1][FILE_C] = &white_queen_;
  board_[RANK_2][FILE_H] = &white_pawn_;
  board_[RANK_8][FILE_E] = &black_king_;
  king_position[0] = FILE_E + 'A';
  king_position[1] = RANK_8 + '1';
  king_position[2] = '\0';
  black_king_position_ = king_position;
  black_king_ = board_[RANK_8][FILE_E];
  // board_[RANK_5][FILE_B] = new Knight(true);
  // board_[RANK_1][FILE_A] = new King(true);
  king_position[0] = FILE_A + 'A';
  king_position[1] = RANK_1 + '1';
  king_position[2] = '\0';
  white_king_position_ = king_position;
  white_king_ptr_ = board_[RANK_1][FILE_A];

  // board_[RANK_8][FILE_A] = black_rook;
  // board_[RANK_8][FILE_B] = black_knight;
  // board_[RANK_8][FILE_C] = black_bishop;
  // board_[RANK_8][FILE_D] = black_queen;
  // board_[RANK_8][FILE_E] = black_king;
  // board_[RANK_8][FILE_F] = black_bishop;
  // board_[RANK_8][FILE_G] = black_knight;
  // board_[RANK_8][FILE_H] = black_rook;
  //
  // board_[RANK_1][FILE_A] = white_rook;
  // board_[RANK_1][FILE_B] = white_knight;
  // board_[RANK_1][FILE_C] = white_bishop;
  // board_[RANK_1][FILE_D] = white_queen;
  // board_[RANK_1][FILE_E] = white_king;
  // board_[RANK_1][FILE_F] = white_bishop;
  // board_[RANK_1][FILE_G] = white_knight;
  // board_[RANK_1][FILE_H] = white_rook;

  // king_position[0] = FILE_E + 'A';
  // king_position[1] = RANK_8 + '1';
  // king_position[2] = '\0';
  // black_king_position_ = king_position;
  // black_king_ = board_[RANK_8][FILE_E];
  // // board_[RANK_5][FILE_B] = new Knight(true);
  // // board_[RANK_1][FILE_A] = new King(true);
  // king_position[0] = FILE_E + 'A';
  // king_position[1] = RANK_1 + '1';
  // king_position[2] = '\0';
  // white_king_position_ = king_position;
  // white_king_ptr_ = board_[RANK_1][FILE_E];
  // board_[RANK_2][FILE_A] = new Pawn(false);
  is_white_turn_ = true;
  printCurrentBoard();
}

ChessBoard::~ChessBoard(){
  // for(int i = 0; i < NUM_OF_PIECES; i++){
  //   delete pieces_[i];
  // }
}

bool ChessBoard::isValidSquare(const string square){
  if(square.length() != 2){
    return false;
  }
  else if(square[0] < 'A' || square[0] > 'H'){
    return false;
  }
  else if(square[1] < '1' || square[1] > '8'){
    return false;
  }

  return true;
}

void ChessBoard::submitMove(const string source_square, const string destination_square){
  // Check if the source square (A-H and 1-8) is valid or not
  if(!isValidSquare(source_square)){
    cout << "source input is not valid" << endl;
    return;
  }

  if(!isValidSquare(destination_square)){
    cout << "destination input is not valid" << endl;
    return;
  }

  Piece* piece = getPiecePtrFromBoard(source_square);
  // TODO Fix the error message when there is a piece in front of a pawn
  if(piece == nullptr){
    cout << "There is no piece in the square you selected" << endl;
    return;
  }

  // Check the piece in the square (exist? and match with current turn?)
  // Check which turn, (white or black?)
  if(is_white_turn_  && !piece->getIsWhite()){
    cout << "It is not White's turn to move!" << endl;
    return;
  }
  if(!is_white_turn_  && piece->getIsWhite()){
    cout << "It is not White's turn to move!" << endl;
    return;
  }

  if(!piece->isValidMove(source_square, destination_square, board_)){
    cout << "You cannot move the piece to " << destination_square << "!" << endl;
  }

  // Check if King is safe

  makeMove(source_square, destination_square);
  // Display the message
  // Update current player (white and black)
  (is_white_turn_) ? is_white_turn_ = false : is_white_turn_ = true;
  piece->negateIsFirstMove();

  vector<string> possible_moves;
  if(is_white_turn_ && is_white_in_check_){
    if(isCheckMate()){
      cout << "white king in checkmate..." << endl;
      return;
    }
    // After moves, check if the king is still safe
  }
  if(!is_white_turn_ && is_black_in_check_){
    if(isCheckMate()){
      cout << "black king in checkmate..." << endl;
      return;
    }
  }

  possible_moves.clear();
}

Piece* ChessBoard::getPiecePtrFromBoard(const string source_square){
  int rank = source_square[1] - '1';
  int file = source_square[0] - 'A';
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

// TODO Can I just use one makeMove? This looks a bit redundant
void ChessBoard::undoMove(string source_square, string destination_square){
  // TODO How can I replace this??
  int dest_file = destination_square[0] - 'A';
  int dest_rank = destination_square[1] - '1';
  Piece* dest_piece = board_[dest_rank][dest_file];

  board_[dest_rank][dest_file] = previous_destination_square_;
  // previous_destination_square_ = pre_pre_dest_square_;

  int source_file = source_square[0] - 'A';
  int source_rank = source_square[1] - '1';
  board_[source_rank][source_file] = dest_piece;

  updateKingPosition(dest_piece, source_square);
}

void ChessBoard::updateKingPosition(Piece* piece_ptr, string piece_square){
  if(piece_ptr->getSimbol() == "WK"){
    white_king_ptr_ = piece_ptr;
    white_king_position_ = piece_square;
  }
  else if(piece_ptr->getSimbol() == "BK"){
    black_king_ptr_ = piece_ptr;
    black_king_position_ = piece_square;
  }
}

void ChessBoard::makeMove(string source_square, string destination_square){
  // Get piece pointer from source square
  int source_file = source_square[0] - 'A';
  int source_rank = source_square[1] - '1';
  Piece* source_piece = board_[source_rank][source_file];

  int dest_file = destination_square[0] - 'A';
  int dest_rank = destination_square[1] - '1';
  // Keep it here in case we need it for undoMove
  pre_pre_dest_square_ = previous_destination_square_;
  previous_destination_square_ = board_[dest_rank][dest_file];

  board_[dest_rank][dest_file] = source_piece;

  board_[source_rank][source_file] = nullptr;

  updateKingPosition(source_piece, destination_square);

  // TODO Abstract this function
  if(is_white_turn_){
    if(!isKingSafe()){
      // TODO Make this more efficient
      cout << "This move makes your king in check, therefore invalid move" << endl;
      undoMove(source_square, destination_square);
      // Undo the move
      // attacking_piece_position_ = ""; Do I need to do this here?
    }else{
      attacking_piece_position_ = "";
      is_white_in_check_ = false;
    }

    if(!isKingSafe()){
      cout << "black king is now in check!!" << endl;
      is_black_in_check_ = true;
    }
  }else{
    if(!isKingSafe()){
      cout << "The move makes your king in check, therefore invalid move" << endl;
      undoMove(source_square, destination_square);
      // attacking_piece_position_ = ""; Do I need to do this here?
    }else{
      attacking_piece_position_ = "";
      is_black_in_check_ = false;
    }
    if(!isKingSafe()){
      cout << "white king is now in check!!" << endl;
      is_white_in_check_ = true;
    }
  }
  cout << "move complete " << endl;
  printCurrentBoard();
}

bool ChessBoard::isKingSafe(){
  char source_square[3];
  string sq;
  for(int rank = RANK_1; rank <= RANK_8; rank++){
    for(int file = FILE_A; file <= FILE_H; file++){
      source_square[0] = file + 'A';
      source_square[1] = rank + '1';
      source_square[2] = '\0';
      sq = source_square;
      // Check if white king is safe
      if(board_[rank][file] != nullptr && is_white_turn_ && \
        !board_[rank][file]->getIsWhite() && \
        board_[rank][file]->isValidMove(sq, white_king_position_, board_)){
        attacking_piece_position_ = sq;
        return false;
      }
      // Check if black king is safe
      else if(board_[rank][file] != nullptr && \
              !is_white_turn_ && board_[rank][file]->getIsWhite() && \
              board_[rank][file]->isValidMove(sq, white_king_position_, board_)){
              attacking_piece_position_ = sq;
              return false;
            }
    }
  }
  return true;
}

bool ChessBoard::isPossibleMoveLeft(){
  for(int rank = RANK_1; rank <  RANK_NONE; rank++){
    for(int file = FILE_A; file < FILE_NONE; file++){
      // if(board_[rank][file] != nullptr &&
      // possible moves left
    }
  }
  return false;
}

bool ChessBoard::isCheckMate(){
  // 1. Check if King can move to escape from in_check
  vector<string>possible_moves;
  if(is_white_turn_){
    white_king_ptr_->calculatePossibleMove(white_king_position_, board_, possible_moves);
    // Try all possible moves for the king, and see if one of them makes the king safe (therefore not checkmate yet)
    for(string move: possible_moves){
      makeMove(white_king_position_, move);
      cout << "what is move? " << move << endl;
      if(isKingSafe()){
        cout << "white king is safe now" << endl;
        undoMove(white_king_position_, move);
        return false;
      }else{
        cout << "white king not safe yet.. " << endl;
        undoMove(white_king_position_, move);
      }
    }

  }else{
    black_king_ptr_->calculatePossibleMove(black_king_position_, board_, possible_moves);
    // TODO Super redundant here
    for(string move: possible_moves){
      makeMove(black_king_position_, move);
      if(isKingSafe()){
        cout << "black king is safe now" << endl;
        undoMove(black_king_position_, move);
        return false;
      }else{
        cout << "black king not safe yet.. " << endl;
        undoMove(black_king_position_, move);
      }
    }
  }
  possible_moves.clear();

  // 2. Check if any piece can capture the opponent's attacking piece
  string sq;
  char square[3];
  for(int file = FILE_A; file <= FILE_H; file++){
    for(int rank = RANK_1; rank <= RANK_8; rank ++){
      if(board_[rank][file] != nullptr){
        square[0] = file + 'A';
        square[1] = rank + '1';
        square[2] = '\0';
        sq = square;

        board_[rank][file]->calculatePossibleMove(sq, board_, possible_moves);
        for(string move: possible_moves){
          cout << "move " << move << endl;
          if(attacking_piece_position_ == move){
            cout << "someone can capture the attacker " << endl;
            printCurrentBoard();
            return false;
          }
        }
        possible_moves.clear();
      }
    }
  }
  // 3. Check if you can interpose between the King and the attacking piece (except knight)

  // if attacking piece is not knight
  vector<string>blocking_squares;
  // if any of my pieces can move to one of blocking_squares, return false
  return true;
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
