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

  char king_position[3];
  board_[RANK_3][FILE_B] = new Queen(false);
  board_[RANK_1][FILE_A] = new King(true);
  board_[RANK_1][FILE_B] = new Pawn(true);
  board_[RANK_1][FILE_C] = new Queen(true);
  board_[RANK_2][FILE_H] = new Pawn(true);
  board_[RANK_8][FILE_E] = new King(false);
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
  white_king_ = board_[RANK_1][FILE_A];
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


  // board_[RANK_1][FILE_E] = new Queen(false);

  // board_[RANK_5][FILE_D] = new Knight(false);

  // board_[RANK_3][FILE_B] = new Pawn(false);

  // board_[RANK_4][FILE_D] = new King(false);
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
  // white_king_ = board_[RANK_1][FILE_E];
  // board_[RANK_2][FILE_A] = new Pawn(false);
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

  // Check if the move destroys an opponent piece
  if(piece->isValidMove(source_square, destination_square, board_)){
    makeMove(source_square, destination_square);
  }
  // Display the message
  // Update current player (white and black)
  (is_white_turn_) ? is_white_turn_ = false : is_white_turn_ = true;
  piece->negateIsFirstMove();

  vector<string> possible_moves;
  cout << "white check? " << is_white_in_check_ << endl;
  cout << "black check? " << is_black_in_check_ << endl;
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

// TODO Can I just use one makeMove? This looks a bit redundant
void ChessBoard::undoMove(string source_square, string destination_square){
  cout << "undoing: source_square " << source_square << endl;
  cout << "undoing: destination_square " << destination_square << endl;
  int dest_file = destination_square.at(0) - 'A';
  int dest_rank = destination_square.at(1) - '1';
  cout << "dest_file " << dest_file << endl;
  cout << "dest_rank " << dest_rank << endl;
  Piece* dest_piece = board_[dest_rank][dest_file];

  board_[dest_rank][dest_file] = previous_destination_square_;
  previous_destination_square_ = pre_pre_dest_square_;
  cout << "previous dest square " << previous_destination_square_ << endl;
  int source_file = source_square.at(0) - 'A';
  int source_rank = source_square.at(1) - '1';
  board_[source_rank][source_file] = dest_piece;
  cout << "dest_piece " << dest_piece << endl;

  if(board_[source_rank][source_file]->getSimbol() == "WK"){
    white_king_ = board_[source_rank][source_file];
    white_king_position_ = source_square;
  }
  else if(board_[source_rank][source_file]->getSimbol() == "BK"){
    black_king_ = board_[source_rank][source_file];
    black_king_position_ = source_square;
  }

  cout << "undoing1" << endl;
  printCurrentBoard();
  cout << "undoing2" << endl;
}

// TODO it is now memory leaking
void ChessBoard::makeMove(string source_square, string destination_square){
  cout << "source_square " << source_square << endl;
  cout << "destination_square " << destination_square << endl;
  // Get piece pointer from source square
  int source_file = source_square.at(0) - 'A';
  int source_rank = source_square.at(1) - '1';
  Piece* source_piece = board_[source_rank][source_file];

  int dest_file = destination_square.at(0) - 'A';
  int dest_rank = destination_square.at(1) - '1';
  // Keep it here in case we need it for undoMove
  pre_pre_dest_square_ = previous_destination_square_;
  previous_destination_square_ = board_[dest_rank][dest_file];
  cout << "!!!previous_destination_square_" << previous_destination_square_<< endl;

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
    if(white_king_->isKingSafe(white_king_position_, board_) != ""){
      // TODO Make this more efficient
      cout << "who is attacking? " << white_king_->isKingSafe(white_king_position_, board_) << endl;
      cerr << "This move makes your king in check, therefore invalid move" << endl;
      undoMove(source_square, destination_square);
      // Undo the move
      // attacking_piece_position_ = ""; Do I need to do this here?
    }else{
      attacking_piece_position_ = "";
      is_white_in_check_ = false;
    }

    if(black_king_->isKingSafe(black_king_position_, board_) != ""){
      attacking_piece_position_ = black_king_->isKingSafe(black_king_position_, board_);
      cout << "who is attacking? " << black_king_->isKingSafe(black_king_position_, board_) << endl;
      cout << "back king is now in check!!" << endl;
      is_black_in_check_ = true;
    }
  }else{
    if(black_king_->isKingSafe(black_king_position_, board_) != ""){
      cout << "who is taacking ? " << black_king_->isKingSafe(black_king_position_, board_) << endl;
      cerr << "The move makes your king in check, therefore invalid move" << endl;
      undoMove(source_square, destination_square);
      // attacking_piece_position_ = ""; Do I need to do this here?
    }else{
      attacking_piece_position_ = "";
      is_black_in_check_ = false;
    }
    if(white_king_->isKingSafe(white_king_position_, board_) != ""){
      cout << "who is attacking? " << white_king_->isKingSafe(white_king_position_, board_) << endl;
      cout << "white king is now in check!!" << endl;
      attacking_piece_position_ = white_king_->isKingSafe(white_king_position_, board_);
      is_white_in_check_ = true;
    }
  }

  cout << "move complete " << endl;
  printCurrentBoard();
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
    white_king_->calculatePossibleMove(white_king_position_, board_, possible_moves);
    // Try all possible moves for the king, and see if one of them makes the king safe (therefore not checkmate yet)
    for(string move: possible_moves){
      makeMove(white_king_position_, move);
      cout << "what is move? " << move << endl;
      if(white_king_->isKingSafe(white_king_position_, board_) == ""){
        cout << "white king is safe now" << endl;
        undoMove(white_king_position_, move);
        return false;
      }else{
        cout << "white king not safe yet.. " << endl;
        undoMove(white_king_position_, move);
      }
    }

  }else{
    black_king_->calculatePossibleMove(black_king_position_, board_, possible_moves);
    // TODO Super redundant here
    for(string move: possible_moves){
      makeMove(black_king_position_, move);
      if(black_king_->isKingSafe(black_king_position_, board_) == ""){
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

void ChessBoard::calculatePossibleMoveToSaveKing(vector<string>&possible_moves){
  string sq;
  char source_square[3];
  for(int rank = RANK_1; rank <= RANK_8; rank++){
    for(int file = FILE_A; file <= FILE_H; file++){
      source_square[0] = file + 'A';
      source_square[1] = rank + '1';
      source_square[2] = '\0';
      sq = source_square;
      // cout << "sq2 " << sq << endl;
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
