
#include "Pawn.h"
#include "Piece.h"
#include "Helper.h"
#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;
Pawn::Pawn(bool white): Piece(white){}

void Pawn::calculatePossibleMove(const string source_square, shared_ptr<Piece> board[][BOARD_LENGTH], vector<string>& possible_moves){
  calculatePawnPossibleMove(source_square, board, possible_moves);
}
void Pawn::calculatePawnPossibleMove(const string source_square, shared_ptr<Piece> board[][BOARD_LENGTH], vector<string>& possible_moves){

  int rank = source_square[1] - '1';
  int file = source_square[0] - 'A';
  bool is_white = board[rank][file]->isWhite();
  string sq;
  // White pawn move forward up
  if(is_white && rank < RANK_8){
    if(board[rank+1][file] == nullptr){
      sq = getStringSquare(file, rank+1);
      possible_moves.push_back(sq);
    }
    if(is_first_move_ && (board[rank+1][file] == nullptr) && (board[rank+2][file] == nullptr) ){
      sq = getStringSquare(file, rank+2);
      possible_moves.push_back(sq);
    }
    // If there is a black piece in the diagonal forward
    if((file < FILE_H) && (board[rank+1][file+1] != nullptr) && (!board[rank+1][file+1]->isWhite())){
      sq = getStringSquare(file+1, rank+1);
      possible_moves.push_back(sq);
    }
    if((file > FILE_A) && (board[rank+1][file-1] != nullptr) && !board[rank+1][file-1]->isWhite()){
      sq = getStringSquare(file-1, rank+1);
      possible_moves.push_back(sq);
    }
  }
  // Black pawn move forward down
  else if(!is_white && rank > RANK_1){
    if(is_first_move_ && (board[rank-1][file] == nullptr) &&(board[rank-2][file] == nullptr)){
      sq = getStringSquare(file, rank-2);
      possible_moves.push_back(sq);
    }
    if(board[rank-1][file] == nullptr){
      sq = getStringSquare(file, rank-1);
      possible_moves.push_back(sq);
    }
    // If there is a white piece in the diagonal forward
    if((file > FILE_A) && (board[rank-1][file-1] != nullptr) && (board[rank-1][file-1]->isWhite())){
      sq = getStringSquare(file-1, rank-1);
      possible_moves.push_back(sq);
    }
    if((file < FILE_H) && (board[rank-1][file+1] != nullptr) && board[rank-1][file+1]->isWhite()){
      sq = getStringSquare(file+1, rank-1);
      possible_moves.push_back(sq);
    }
  }
}

string Pawn::getString(){
  return (is_white_)? "White's Pawn": "Black's Pawn";
}

string Pawn::getSimbol(){
  return (is_white_)? "WP": "BP";
}
