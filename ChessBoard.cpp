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
#include <vector>

using namespace std;

ChessBoard::ChessBoard(){
  for(int rank = RANK_1; rank <= RANK_8; rank++){
    for(int file = FILE_A; file <= FILE_H; file++){
      board_[rank][file] = nullptr;
    }
  }

  resetBoard();
  // is_white_in_check_ = false;
  // is_black_in_check_ = false;
  //
  // char king_position[3];
  // board_[RANK_3][FILE_B] = new Queen(false);
  // board_[RANK_1][FILE_A] = new King(true);
  // board_[RANK_1][FILE_B] = new Pawn(true);
  // board_[RANK_1][FILE_C] = new Queen(true);
  // board_[RANK_2][FILE_H] = new Pawn(true);
  // board_[RANK_8][FILE_E] = new King(false);
  // board_[RANK_2][FILE_A] = new Pawn(false);
  // king_position[0] = FILE_E + 'A';
  // king_position[1] = RANK_8 + '1';
  // king_position[2] = '\0';
  // black_king_position_ = king_position;
  // black_king_ptr_ = board_[RANK_8][FILE_E];
  //
  // king_position[0] = FILE_A + 'A';
  // king_position[1] = RANK_1 + '1';
  // king_position[2] = '\0';
  // white_king_position_ = king_position;
  // white_king_ptr_ = board_[RANK_1][FILE_A];
  // is_white_turn_ = true;

  printCurrentBoard();
}

ChessBoard::~ChessBoard(){
  cleanBoard();
}

// TODO Use this more often
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
  cout << "source_square " << source_square << endl;
  cout << "destination_square " << destination_square << endl;
  cout << "who's turn?? " << is_white_turn_ << endl;
  if(is_game_finished){
    cout << "Game is finished" << endl;
    return;
  }
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
  if(piece == nullptr){
    cout << "There is no piece in the square you selected" << endl;
    return;
  }

  // Check the piece in the square (exist? and match with current turn?)
  // Check which turn, (white or black?)
  if(is_white_turn_  && !piece->isWhite()){
    cout << "It is not White's turn to move!" << endl;
    return;
  }
  if(!is_white_turn_  && piece->isWhite()){
    cout << "It is not White's turn to move!" << endl;
    return;
  }

  if(!piece->isValidMove(source_square, destination_square, board_)){
    cout << "You cannot move the piece to " << destination_square << "!" << endl;
    return;
  }

  // Check if King is safe
  makeMove(source_square, destination_square);
  // After moves, check if your own king is still safe
  if(!isKingSafe(true)){
    cout << "You cannot move the piece to " << destination_square << "!" << endl;
    undoMove(source_square, destination_square);
  }
  if(!isKingSafe(false)){
    cout << "check!!" << endl;
  }

  // TODO Double check if this logic is correct
  else{
    is_black_in_check_ = false;
    is_white_in_check_ = false;
  }

  if(!isPossibleMoveLeft()){
    cout << "possible move left false " << endl;
    if(is_white_in_check_){
      cout << "White is in checkmate" << endl;
      is_game_finished = true;
      return;
    }
    else if(is_black_in_check_){
      cout << "Black is in checkmate" << endl;
      is_game_finished = true;
      return;
    }
    else{
      cout << "Stalemate" << endl;
      is_game_finished = true;
      return;
    }
  }

  // Update current player (white and black)
  is_white_turn_ = !(is_white_turn_);

  piece->negateIsFirstMove();
  printCurrentBoard();
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

// TODO Do I need this?
// Getter for is_white_turn
bool ChessBoard::isWhiteTurn(){
  return is_white_turn_;
}

void ChessBoard::undoMove(string source_square, string destination_square){
  // TODO How can I replace this??
  int dest_file = destination_square[0] - 'A';
  int dest_rank = destination_square[1] - '1';
  Piece* dest_piece = board_[dest_rank][dest_file];

  board_[dest_rank][dest_file] = previous_destination_square_;

  int source_file = source_square[0] - 'A';
  int source_rank = source_square[1] - '1';
  board_[source_rank][source_file] = dest_piece;

  updateKingPosition(dest_piece, source_square);
  // cout << "Undo complete" << endl;
  // printCurrentBoard();
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
  // cout << "within makemove, source_square " << source_square << endl;
  // cout << "within makemove, destination_square " << destination_square << endl;

  if(source_square == "F8" && destination_square == "B4"){
    cout << "stop" << endl;
  }
  // Get piece pointer from source square
  int source_file = source_square[0] - 'A';
  int source_rank = source_square[1] - '1';
  Piece* source_piece = board_[source_rank][source_file];

  int dest_file = destination_square[0] - 'A';
  int dest_rank = destination_square[1] - '1';
  // if(previous_destination_square_ != nullptr){
  //   delete previous_destination_square_;
  // }
  previous_destination_square_ = board_[dest_rank][dest_file];

  board_[dest_rank][dest_file] = source_piece;

  board_[source_rank][source_file] = nullptr;

  updateKingPosition(source_piece, destination_square);
  cout << "move complete " << endl;
  // printCurrentBoard();
}

bool ChessBoard::isKingSafe(bool my_king){
  char source_square[3];
  string sq;
  for(int rank = RANK_1; rank <= RANK_8; rank++){
    for(int file = FILE_A; file <= FILE_H; file++){
      source_square[0] = file + 'A';
      source_square[1] = rank + '1';
      source_square[2] = '\0';
      sq = source_square;
      // Check if my king is safe
      if(board_[rank][file] != nullptr){
        if(my_king){
          if(is_white_turn_ && !board_[rank][file]->isWhite() && board_[rank][file]->isValidMove(sq, white_king_position_, board_)){
            cout << "illigal move" << endl;
            return false;
          }
          // cout << "balck position " << black_king_position_ << endl;
          if(!is_white_turn_ && board_[rank][file]->isWhite() && board_[rank][file]->isValidMove(sq, black_king_position_, board_)){
            cout << "illigal move" << endl;
            return false;
          }
        }
        // Check if opponent king is in check
        else{
          // When white_turn, opponent king  is white king
          if(is_white_turn_ && board_[rank][file]->isWhite() && board_[rank][file]->isValidMove(sq, black_king_position_, board_)){
            cout << "black king in check" << endl;
            is_black_in_check_ = true;
            return false;
          }
          // When black turn, my king is black king
          else if(!is_white_turn_ && !board_[rank][file]->isWhite() && board_[rank][file]->isValidMove(sq, white_king_position_, board_)){
            cout << "white king in check " << endl;
            is_white_in_check_ = true;
            return false;
          }
        }
      }
    }
  }
  return true;
}

bool ChessBoard::isPossibleMoveLeft(){
  vector<string>possible_moves;
  char source_square[3];
  string sq;
  char destination_square[3];
  string sq2;
  for(int rank = RANK_1; rank <=  RANK_8; rank++){
    for(int file = FILE_A; file <= FILE_H; file++){
      // When the square is not null and opposite color
      if(board_[rank][file] != nullptr && (board_[rank][file]->isWhite() != is_white_turn_)){
      // if(board_[rank][file] != nullptr ){
        source_square[0] = file + 'A';
        source_square[1] = rank + '1';
        source_square[2] = '\0';
        sq = source_square;
        for(int r = RANK_1; r <= RANK_8; r++){
          for(int f = FILE_A; f <= FILE_H; f++){
            destination_square[0] = f + 'A';
            destination_square[1] = r + '1';
            destination_square[2] = '\0';
            sq2 = destination_square;
            if(board_[rank][file]->isValidMove(sq, sq2, board_)){
              makeMove(sq, sq2);
              // Check if your own king is still safe
              if(!isKingSafe(false)){
                undoMove(sq, sq2);
              }else{
                undoMove(sq, sq2);
                // cout << "what is the possible move? " << sq << " to " << sq2 << endl;
                return true;
              }
            }
          }
        }
      }
    }
  }
  return false;
}

void ChessBoard::cleanBoard(){
  for(int rank = RANK_1; rank <= RANK_8; rank++){
    for(int file = FILE_A; file <= FILE_H; file++){
      if(board_[rank][file] != nullptr){
        delete board_[rank][file];
      }
    }
  }
}

void ChessBoard::resetBoard(){
  cleanBoard();
  is_game_finished = false;
  is_white_in_check_ = false;
  is_black_in_check_ = false;

  for(int file = FILE_A; file < FILE_NONE; file++){
    board_[RANK_2][file] = new Pawn(true);
    board_[RANK_7][file] = new Pawn(false);
  }
  for(int rank = RANK_3; rank <= RANK_6; rank++){
    for(int file = FILE_A; file < FILE_NONE; file++){
      board_[rank][file] = nullptr;
    }
  }
  board_[RANK_8][FILE_A] = new Rook(false);
  board_[RANK_8][FILE_B] = new Knight(false);
  board_[RANK_8][FILE_C] = new Bishop(false);
  board_[RANK_8][FILE_D] = new Queen(false);
  board_[RANK_8][FILE_E] = new King(false);
  board_[RANK_8][FILE_F] = new Bishop(false);
  board_[RANK_8][FILE_G] = new Knight(false);
  board_[RANK_8][FILE_H] = new Rook(false);

  board_[RANK_1][FILE_A] = new Rook(true);
  board_[RANK_1][FILE_B] = new Knight(true);
  board_[RANK_1][FILE_C] = new Bishop(true);
  board_[RANK_1][FILE_D] = new Queen(true);
  board_[RANK_1][FILE_E] = new King(true);
  board_[RANK_1][FILE_F] = new Bishop(true);
  board_[RANK_1][FILE_G] = new Knight(true);
  board_[RANK_1][FILE_H] = new Rook(true);

  char king_position[3];
  king_position[0] = FILE_E + 'A';
  king_position[1] = RANK_8 + '1';
  king_position[2] = '\0';
  black_king_position_ = king_position;
  black_king_ptr_ = board_[RANK_8][FILE_E];

  king_position[0] = FILE_E + 'A';
  king_position[1] = RANK_1 + '1';
  king_position[2] = '\0';
  white_king_position_ = king_position;
  white_king_ptr_ = board_[RANK_1][FILE_E];

  previous_destination_square_ = nullptr;
  is_white_turn_ = true;
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
