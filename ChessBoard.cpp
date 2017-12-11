#include "ChessBoard.h"
#include "Pawn.h"
#include "Queen.h"
#include "King.h"
#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"

#include "Helper.h"

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

  // printCurrentBoard();
}

ChessBoard::~ChessBoard(){
  cleanBoard();
}

// TODO Use this more often
bool ChessBoard::isValidInput(const string square){
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
  // cout << "source_square " << source_square << endl;
  // cout << "destination_square " << destination_square << endl;
  // cout << "who's turn?? " << is_white_turn_ << endl;
  if(is_game_finished){
    cout << "Game is finished" << endl;
    return;
  }
  // Check if the source square (A-H and 1-8) is valid or not
  if(!isValidInput(source_square)){
    cout << "source input is not valid" << endl;
    return;
  }

  if(!isValidInput(destination_square)){
    cout << "destination input is not valid" << endl;
    return;
  }

  Piece* piece = getPiecePtrFromBoard(source_square);
  if(piece == nullptr){
    cout << "There is no piece at position " << source_square << endl;
    return;
  }

  int rank = destination_square[1] - '1';
  int file = destination_square[0] - 'A';
  Piece* dest_piece = nullptr;
  if(board_[rank][file] != nullptr){
    dest_piece = getPiecePtrFromBoard(destination_square);
  }

  if(is_white_turn_  && !piece->isWhite()){
    cout << "It is not White's turn to move!" << endl;
    return;
  }
  if(!is_white_turn_  && piece->isWhite()){
    cout << "It is not White's turn to move!" << endl;
    return;
  }

  if(!piece->isValidMove(source_square, destination_square, board_)){
    cout << piece->getString() << " cannot move to " << destination_square << "!" << endl;
    return;
  }

  // Check if King is safe
  makeMove(source_square, destination_square);
  // After moves, check if your own king is still safe
  if(!isKingSafe(true)){
    cout << piece->getString() << " cannot move to " << destination_square << "!" << endl;
    undoMove(source_square, destination_square);
  }

  if(!isKingSafe(false)){
    if(is_white_turn_){
      is_black_in_check_ = true;
    }else{
      is_white_in_check_ = true;
    }
  }
  // TODO Double check if this logic is correct
  else{
    is_black_in_check_ = false;
    is_white_in_check_ = false;
  }

  cout << piece->getString() << " moves from " << source_square << " to " << destination_square;
  if(dest_piece != nullptr){
    cout << " taking " << dest_piece->getString();
  }
  cout << endl;

  if(!isPossibleMoveLeft()){
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

  if(is_white_in_check_){
    cout << "White is in check" << endl;
  }
  if(is_black_in_check_){
    cout << "Black is in check" << endl;
  }

  // Update the current player (white and black)
  is_white_turn_ = !(is_white_turn_);

  piece->negateIsFirstMove();
  // printCurrentBoard();
}

void ChessBoard::undoMove(string source_square, string destination_square){
  // TODO How can I replace this??
  int dest_file = getFileInt(destination_square);
  int dest_rank = getRankInt(destination_square);
  Piece* dest_piece = board_[dest_rank][dest_file];

  board_[dest_rank][dest_file] = previous_destination_square_;

  int source_file = getFileInt(source_square);
  int source_rank = getRankInt(source_square);
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

Piece* ChessBoard::getPiecePtrFromBoard(const string source_square){
  int rank = source_square[1] - '1';
  int file = source_square[0] - 'A';
  return board_[rank][file];
}

bool ChessBoard::isNoPieceBetweenKingRook(string king_position, string rook_position){
  int king_file = getFileInt(king_position);
  int king_rank = getRankInt(king_position);
  // Rook rank is the same as king's, so we do not need it
  int rook_file = getFileInt(rook_position);

  if(king_file > rook_file){
    for(int file = rook_file+1; file < king_file; file++){
      if(board_[king_rank][file] != nullptr){
        return false;
      }
    }
  }
  else{
    for(int file = king_file+1; file < rook_file; file++){
      if(board_[king_rank][file] != nullptr){
        return false;
      }
    }
  }

  return true;
}

void ChessBoard::checkCastling(const string source_square, const string destination_square){

  // Piece* piece = getPiecePtrFromBoard(source_square);
  // If we are not moving king, exit the method
  if(source_square != white_king_position_ && source_square != black_king_position_){
    return;
  }

  // Check if the involved rook and king have not being moved
  Piece* rook = nullptr;
  // && white_king_ptr_->isWhite()
  if(white_king_ptr_->isFirstMove()){
    // Rook on Queen side
    if(board_[RANK_1][FILE_A] != nullptr){
        rook = getPiecePtrFromBoard("A1");
    }
    // TODO I do not want to hardcode A1....
    if(!is_white_in_check_ && rook->isFirstMove() && isNoPieceBetweenKingRook(source_square, "A1")){

    }
    // Rook on King side
    rook = board_[RANK_1][FILE_H];
    if(!is_white_in_check_ && rook->isFirstMove() && isNoPieceBetweenKingRook(source_square, "H1")){

    }
  }

  // The king is not currently in check


  // The king does not pass through a square that is attacked by an opponent piece
  // The king does not end up in check

  // Finally, move Rook
}


void ChessBoard::makeMove(string source_square, string destination_square){
  // cout << "within makemove, source_square " << source_square << endl;
  // cout << "within makemove, destination_square " << destination_square << endl;
  // Get piece pointer from source square
  int source_file = getFileInt(source_square);
  int source_rank = getRankInt(source_square);
  Piece* source_piece = board_[source_rank][source_file];

  int dest_file = getFileInt(destination_square);
  int dest_rank = getRankInt(destination_square);
  // if(previous_destination_square_ != nullptr){
  //   delete previous_destination_square_;
  // }
  previous_destination_square_ = board_[dest_rank][dest_file];

  board_[dest_rank][dest_file] = source_piece;

  board_[source_rank][source_file] = nullptr;
  // These two methods are only triggered when a king moves
  // checkCastling(source_square, destination_square);
  updateKingPosition(source_piece, destination_square);
  // cout << "move complete " << endl;
}

bool ChessBoard::isKingSafe(bool my_king){
  // TODO Change name
  string square;
  for(int rank = RANK_1; rank <= RANK_8; rank++){
    for(int file = FILE_A; file <= FILE_H; file++){
      square = getStringSquare(file, rank);
      // Check if my king is safe
      if(board_[rank][file] != nullptr){
        if(my_king){
          if(is_white_turn_ && !board_[rank][file]->isWhite() && board_[rank][file]->isValidMove(square, white_king_position_, board_)){
            cout << "illigal move" << endl;
            return false;
          }
          if(!is_white_turn_ && board_[rank][file]->isWhite() && board_[rank][file]->isValidMove(square, black_king_position_, board_)){
            cout << "illigal move" << endl;
            return false;
          }
        }
        // Check if opponent king is in check
        else{
          // When white_turn, opponent king  is white king
          if(is_white_turn_ && board_[rank][file]->isWhite() && board_[rank][file]->isValidMove(square, black_king_position_, board_)){
            return false;
          }
          // When black turn, my king is black king
          else if(!is_white_turn_ && !board_[rank][file]->isWhite() && board_[rank][file]->isValidMove(square, white_king_position_, board_)){
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
  string sq;
  string sq2;
  for(int rank = RANK_1; rank <=  RANK_8; rank++){
    for(int file = FILE_A; file <= FILE_H; file++){
      // When the square is not null and opposite color
      if(board_[rank][file] != nullptr && (board_[rank][file]->isWhite() != is_white_turn_)){
        sq = getStringSquare(file, rank);
        // TODO Abstract this away
        for(int r = RANK_1; r <= RANK_8; r++){
          for(int f = FILE_A; f <= FILE_H; f++){
            sq2 = getStringSquare(f, r);
            if(board_[rank][file]->isValidMove(sq, sq2, board_)){
              makeMove(sq, sq2);
              // Check if your own king is still safe
              if(!isKingSafe(false)){
                undoMove(sq, sq2);
              }else{
                undoMove(sq, sq2);
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

  black_king_position_ = getStringSquare(FILE_E, RANK_8);
  black_king_ptr_ = board_[RANK_8][FILE_E];

  white_king_position_ = getStringSquare(FILE_E, RANK_1);
  white_king_ptr_ = board_[RANK_1][FILE_E];

  previous_destination_square_ = nullptr;
  is_white_turn_ = true;
  cout << "A new chess game is started!" << endl;
}

// TODO Delete this
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
