#include "Helper.h"
#include "Piece.h"
#include "ChessBoard.h"
#include "Pawn.h"
#include "Queen.h"
#include "King.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"

#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

ChessBoard::ChessBoard(){
  for(int rank = RANK_1; rank <= RANK_8; rank++){
    for(int file = FILE_A; file <= FILE_H; file++){
      board_[rank][file] = nullptr;
    }
  }
  resetBoard();
}

void ChessBoard::resetBoard(){
  is_game_finished = false;
  is_white_in_check_ = false;
  is_black_in_check_ = false;

  for(int file = FILE_A; file < FILE_NONE; file++){
    board_[RANK_2][file] = make_shared<Pawn>(true);
    board_[RANK_7][file] = make_shared<Pawn>(false);
  }
  for(int rank = RANK_3; rank <= RANK_6; rank++){
    for(int file = FILE_A; file < FILE_NONE; file++){
      board_[rank][file] = nullptr;
    }
  }
  board_[RANK_8][FILE_A] = make_shared<Rook>(false);
  board_[RANK_8][FILE_B] = make_shared<Knight>(false);
  board_[RANK_8][FILE_C] = make_shared<Bishop>(false);
  board_[RANK_8][FILE_D] = make_shared<Queen>(false);
  board_[RANK_8][FILE_E] = make_shared<King>(false);
  board_[RANK_8][FILE_F] = make_shared<Bishop>(false);
  board_[RANK_8][FILE_G] = make_shared<Knight>(false);
  board_[RANK_8][FILE_H] = make_shared<Rook>(false);

  board_[RANK_1][FILE_A] = make_shared<Rook>(true);
  board_[RANK_1][FILE_B] = make_shared<Knight>(true);
  board_[RANK_1][FILE_C] = make_shared<Bishop>(true);
  board_[RANK_1][FILE_D] = make_shared<Queen>(true);
  board_[RANK_1][FILE_E] = make_shared<King>(true);
  board_[RANK_1][FILE_F] = make_shared<Bishop>(true);
  board_[RANK_1][FILE_G] = make_shared<Knight>(true);
  board_[RANK_1][FILE_H] = make_shared<Rook>(true);

  black_king_position_ = getStringSquare(FILE_E, RANK_8);
  black_king_ptr_ = board_[RANK_8][FILE_E];

  white_king_position_ = getStringSquare(FILE_E, RANK_1);
  white_king_ptr_ = board_[RANK_1][FILE_E];

  previous_destination_square_ = nullptr;
  is_white_turn_ = true;
  cout << "A new chess game is started!" << endl;
}

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

shared_ptr<Piece> ChessBoard::getPiecePtrFromBoard(const string source_square){
  int rank = getRankInt(source_square);
  int file = getFileInt(source_square);
  return board_[rank][file];
}

void ChessBoard::submitMove(const string source_square, \
                            const string destination_square){
  if(is_game_finished){
    cerr << "Game is finished" << endl;
    return;
  }
  // Check if the source square (A-H and 1-8) is valid or not
  if(!isValidInput(source_square)){
    cerr << "source input is not valid" << endl;
    return;
  }

  if(!isValidInput(destination_square)){
    cerr << "destination input is not valid" << endl;
    return;
  }

  shared_ptr<Piece> piece = getPiecePtrFromBoard(source_square);
  if(piece == nullptr){
    cerr << "There is no piece at position " << source_square << endl;
    return;
  }

  int file = getFileInt(destination_square);
  int rank = getRankInt(destination_square);

  // dest_piece is used to print message when a piece captures an opponent piece
  shared_ptr<Piece> dest_piece = nullptr;
  if(board_[rank][file] != nullptr){
    dest_piece = getPiecePtrFromBoard(destination_square);
  }

  if(is_white_turn_  && !piece->isWhite()){
    cerr << "It is not White's turn to move!" << endl;
    return;
  }
  if(!is_white_turn_  && piece->isWhite()){
    cerr << "It is not White's turn to move!" << endl;
    return;
  }
  // If the move is not castling, do the nomal move.
  // If castling, castling move happens inside isCastling()
  if(!isCastling(source_square, destination_square)){
    if(!piece->isValidMove(source_square, destination_square, board_)){
      cerr << piece->getString() << " cannot move to " << \
      destination_square << "!" << endl;
      return;
    }
    makeMove(source_square, destination_square);
    // After moves, check if your king is still safe
    if(!isKingSafe(true)){
      cerr << piece->getString() << " cannot move to " << \
      destination_square << "!" << endl;
      undoMove(source_square, destination_square);
      return;
    }
    checkKingStatus();
  }

  // Message for the move
  cout << piece->getString() << " moves from " \
  << source_square << " to " << destination_square;
  if(dest_piece != nullptr){
    cout << " taking " << dest_piece->getString();
  }
  cout << endl;

  if(!canGameContinue()){
    return;
  }

  // print message when in_check
  if(is_white_in_check_){
    cout << "White is in check" << endl;
  }
  if(is_black_in_check_){
    cout << "Black is in check" << endl;
  }

  // Update the current player (white and black)
  is_white_turn_ = !(is_white_turn_);

  piece->negateIsFirstMove();
}

void ChessBoard::makeMove(const string source_square, const string destination_square){
  // Get piece pointer from source square
  int source_file = getFileInt(source_square);
  int source_rank = getRankInt(source_square);
  shared_ptr<Piece> source_piece = board_[source_rank][source_file];

  int dest_file = getFileInt(destination_square);
  int dest_rank = getRankInt(destination_square);

  // Keep a pointer in the destination square so that we can reverse the move
  // when undoMove is called
  previous_destination_square_ = board_[dest_rank][dest_file];

  // Update the pointer in the board
  board_[dest_rank][dest_file] = source_piece;
  board_[source_rank][source_file] = nullptr;
  // This method is only triggered when a king moves
  updateKingPosition(source_piece, destination_square);
}

void ChessBoard::undoMove(const string source_square, const string destination_square){
  int dest_file = getFileInt(destination_square);
  int dest_rank = getRankInt(destination_square);
  shared_ptr<Piece> dest_piece = board_[dest_rank][dest_file];

  board_[dest_rank][dest_file] = previous_destination_square_;

  int source_file = getFileInt(source_square);
  int source_rank = getRankInt(source_square);
  board_[source_rank][source_file] = dest_piece;

  updateKingPosition(dest_piece, source_square);
}

void ChessBoard::checkKingStatus(){
  if(!isKingSafe(false)){
    if(is_white_turn_){
      is_black_in_check_ = true;
    }else{
      is_white_in_check_ = true;
    }
  }
  else{
    is_black_in_check_ = false;
    is_white_in_check_ = false;
  }
}

bool ChessBoard::isKingSafe(bool my_king){
  string square;
  for(int rank = RANK_1; rank <= RANK_8; rank++){
    for(int file = FILE_A; file <= FILE_H; file++){
      square = getStringSquare(file, rank);
      // Check if my king is safe
      if(board_[rank][file] != nullptr){
        if(my_king){
          // Check if any black piece can capture white king
          // If there is a valid move, the king is not safe
          if(is_white_turn_ && !board_[rank][file]->isWhite() && \
             board_[rank][file]->isValidMove(square, white_king_position_, \
             board_)){
            return false;
          }
          // Check if any white piece can capture black king
          // If there is a valid move, the king is not safe
          if(!is_white_turn_ && board_[rank][file]->isWhite() && \
             board_[rank][file]->isValidMove(square, black_king_position_, \
             board_)){
            return false;
          }
        }
        // Check if opponent king is in check
        else{
          if(is_white_turn_ && board_[rank][file]->isWhite() && \
             board_[rank][file]->isValidMove(square, black_king_position_, \
             board_)){
            return false;
          }
          // When black turn, my king is black king
          else if(!is_white_turn_ && !board_[rank][file]->isWhite() && \
                  board_[rank][file]->isValidMove(square, white_king_position_, \
                  board_)){
            return false;
          }
        }
      }
    }
  }
  return true;
}

void ChessBoard::updateKingPosition(shared_ptr<Piece> piece_ptr, \
                                    const string piece_square){
  if(piece_ptr->getSimbol() == "WK"){
    white_king_ptr_ = piece_ptr;
    white_king_position_ = piece_square;
  }
  else if(piece_ptr->getSimbol() == "BK"){
    black_king_ptr_ = piece_ptr;
    black_king_position_ = piece_square;
  }
}

bool ChessBoard::isPossibleMoveLeft(){
  // Loop through the entire board
  for(int rank = RANK_1; rank <=  RANK_8; rank++){
    for(int file = FILE_A; file <= FILE_H; file++){
      // When the square is not empty and has a piece of different color,
      // check if it can move anywhere given that the king is safe.
      if(board_[rank][file] != nullptr && \
        (board_[rank][file]->isWhite() != is_white_turn_)){
          if(isPossibleDestinationLeft(file, rank)){
            return true;
          }
      }
    }
  }
  return false;
}

bool ChessBoard::isPossibleDestinationLeft(int source_file, int source_rank){
  string source_square = getStringSquare(source_file, source_rank);
  string dest_square;
  for(int dest_rank = RANK_1; dest_rank <= RANK_8; dest_rank++){
    for(int dest_file = FILE_A; dest_file <= FILE_H; dest_file++){
      dest_square = getStringSquare(dest_file, dest_rank);
      // If valid move, call makeMove and see if the king is still safe.
      if(board_[source_rank][source_file]->isValidMove(source_square, \
                                                       dest_square, board_)){
        makeMove(source_square, dest_square);
        if(!isKingSafe(false)){
          undoMove(source_square, dest_square);
        }else{
          undoMove(source_square, dest_square);
          return true;
        }
      }
    }
  }
  return false;
}

bool ChessBoard::canGameContinue(){
  if(!isPossibleMoveLeft()){
    if(is_white_in_check_){
      cout << "White is in checkmate" << endl;
      is_game_finished = true;
      return false;
    }
    else if(is_black_in_check_){
      cout << "Black is in checkmate" << endl;
      is_game_finished = true;
      return false;
    }
    else{
      cout << "Stalemate" << endl;
      is_game_finished = true;
      return false;
    }
  }
  return true;
}

bool ChessBoard::isNoPieceBetweenKingRook(const string king_position, \
                                          const string rook_position){
  int king_file = getFileInt(king_position);
  int king_rank = getRankInt(king_position);
  // Rook rank is the same as king's, so we do not need it
  int rook_file = getFileInt(rook_position);

  // Queen side castling
  if(king_file > rook_file){
    for(int file = rook_file+1; file < king_file; file++){
      if(board_[king_rank][file] != nullptr){
        return false;
      }
    }
  }
  // King side castling
  else{
    for(int file = king_file+1; file < rook_file; file++){
      if(board_[king_rank][file] != nullptr){
        return false;
      }
    }
  }
  return true;
}

string ChessBoard::getRookPosition(const string destination_square){
  if(destination_square == "C1"){
    return "A1";
  }
  else if(destination_square == "G1"){
    return "H1";
  }
  else if(destination_square == "C8"){
    return "A8";
  }
  else if(destination_square == "G8"){
    return "H8";
  }
  return "";
}

bool ChessBoard::isCastling(const string source_square, \
                               const string destination_square){

  // If we are not moving king, exit the method
  if(source_square != white_king_position_ && \
     source_square != black_king_position_){
    return false;
  }

  int source_file = getFileInt(source_square);
  int source_rank = getRankInt(source_square);
  int dest_file = getFileInt(destination_square);
  int dest_rank = getRankInt(destination_square);

  // Check if the king intends to do castling
  if(abs(source_file - dest_file) != 2 || abs(source_rank - dest_rank) != 0){
    return false;
  }

  shared_ptr<Piece> king_ptr = ((is_white_turn_)? \
  white_king_ptr_ : black_king_ptr_);
  bool in_check = (king_ptr->isWhite())? \
  is_white_in_check_ : is_black_in_check_;

  // Get Rook position and pointer based on the destination of the king
  string rook_position = getRookPosition(destination_square);
  shared_ptr<Piece> rook_ptr = getPiecePtrFromBoard(rook_position);

  // Check if both pieces have not been moved
  if(rook_ptr == nullptr || !rook_ptr->isFirstMove() || \
     !king_ptr->isFirstMove()){
    return false;
  }

  // Check if the king is not in check
  // and no piece between king and rook
  if(!in_check && isNoPieceBetweenKingRook(source_square, rook_position)){
    // King side castling
    if(source_file - dest_file < 0){
      if(!isKingSafeWhileCastling(source_square, destination_square, 1, 2)){
        return false;
      }
    }
    // Queen side castling
    else{
      if(!isKingSafeWhileCastling(source_square, destination_square, -1, -2)){
        return false;
      }
    }
  }

  // Finally, move Rook
  moveRookCastling(rook_position);
  return true;
}

void ChessBoard::moveRookCastling(string rook_position){
  int file = getFileInt(rook_position);
  int rank = getRankInt(rook_position);
  string dest_square;
  // If queen side castling, rook moves 3 squares to right
  if(file == FILE_A){
    dest_square = getStringSquare(file+3, rank);
  }
  // if king side castling, rook moves 2 squares to left
  else if(file == FILE_H){
    dest_square = getStringSquare(file-2, rank);
  }

  makeMove(rook_position, dest_square);
  // Check if the Rook move makes the opponent king in check
  checkKingStatus();
}

bool ChessBoard::isKingSafeWhileCastling(const string source_square, \
                                         const string destination_square, \
                                         int first, int second){
  int source_file = getFileInt(source_square);
  int rank = getRankInt(source_square);
  string dest_square;
  // Check if the king does not pass through a square
  // that is attacked by opponent piecee
  dest_square = getStringSquare(source_file+first, rank);
  makeMove(source_square, dest_square);
  if(!isKingSafe(true)){
    undoMove(source_square, dest_square);
    return false;
  }{
    undoMove(source_square, dest_square);
  }
  // Check if the king does not end up in check
  dest_square = getStringSquare(source_file+second, rank);
  makeMove(source_square, dest_square);
  if(!isKingSafe(true)){
    undoMove(source_square, dest_square);
    return false;
  }
  return true;
}
