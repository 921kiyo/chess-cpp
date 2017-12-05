#include "Piece.h"
#include "Definitions.h"

#include <iostream>
#include <string>
using namespace std;

Piece::Piece(bool white): is_white_(white), is_first_move_(true){}

Piece::~Piece(){}

bool Piece::isValidMove(const string source_square, const string destination_square, Piece* board[8][8]){
  // DO I need const here??
  vector<string> possible_moves;

  calculatePossibleMove(source_square, board, possible_moves);
  // C++11 Range-based loop
  for(string square: possible_moves){
    cout << "sq " << square << endl;
    if(destination_square == square){
      cout << "yes" << endl;
      return true;
    }

  }

  return false;

  // Check if the move makes the king in check.
  // isKingSafe()

  // Or Castling
}

bool Piece::getIsWhite(){
  return is_white_;
}

void Piece::negateIsFirstMove(){
  if(is_first_move_){
    is_first_move_ = false;
  }
}

bool Piece::checkSquare(int rank, int file, bool is_white, Piece* board[8][8], vector<string>& possible_moves){
  char square[3];
  string sq;
  if(rank < RANK_1 || rank > RANK_8 || file < FILE_A || file > FILE_H){
    return false;
  }
  if(board[rank][file] != NULL && is_white == board[rank][file]->getIsWhite()){
    return false;
  }
  else if(board[rank][file] != NULL && is_white != board[rank][file]->getIsWhite()){
    square[0] = file + 'A';
    square[1] = rank + '1';
    square[2] = '\0';
    sq = square;
    possible_moves.push_back(sq);
    cout << "square " << square << endl;
    return false;
  }
  else if(board[rank][file] == NULL){
     square[0] = file + 'A';
     square[1] = rank + '1';
     square[2] = '\0';
     sq = square;
     possible_moves.push_back(sq);
     cout << "square " << square << endl;
     return true;
  }
}

void Piece::calculateVerticalPossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves){
  int rank = source_square.at(1) - '1';
  int file = source_square.at(0) - 'A';
  bool is_white = board[rank][file]->getIsWhite();
  // Check vertical lines to the top
  for(int r = rank+1; r <= RANK_8; r++){
    if(!checkSquare(r, file, is_white, board, possible_moves)){
      break;
    }
  }
  // Check vertical line to the bottom
  for(int r = rank-1; r >= RANK_1; r--){
    if(!checkSquare(r, file, is_white, board, possible_moves)){
      break;
    }
  }
}

void Piece::calculateHorizontalPossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves){
  int rank = source_square.at(1) - '1';
  int file = source_square.at(0) - 'A';
  bool is_white = board[rank][file]->getIsWhite();
  // Check horizontal lines to the right
  for(int f = file+1; f <= FILE_H; f++){
    if(!checkSquare(rank, f, is_white, board, possible_moves)){
      break;
    }
  }
  // Check horizontal lines to the left
  for(int f = file-1; f >= FILE_A; f--){
    if(!checkSquare(rank, f, is_white, board, possible_moves)){
      break;
    }
  }
}

void Piece::calculateDiagonalPossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves){
  int rank = source_square.at(1) - '1';
  int file = source_square.at(0) - 'A';
  bool is_white = board[rank][file]->getIsWhite();
  // Check giagonal lines
  int r = rank+1;
  for(int f = file+1; f <= FILE_H; f++){
    if(!checkSquare(r, f, is_white, board, possible_moves)){
      break;
    }
    r++;
  }

  r = rank-1;
  for(int f = file+1; f <= FILE_H; f++){
    if(!checkSquare(r, f, is_white, board, possible_moves)){
      break;
    }
    r--;
  }

  r = rank+1;
  for(int f = file-1; f >= FILE_A; f--){
    if(!checkSquare(r, f, is_white, board, possible_moves)){
      break;
    }
    r++;
  }
  // Reset r
  r = rank-1;
  for(int f = file-1; f >= FILE_A; f--){
    if(!checkSquare(r, f, is_white, board, possible_moves)){
      break;
    }
    r--;
  }
}

void Piece::calculateAdjacentPossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves){
  int rank = source_square.at(1) - '1';
  int file = source_square.at(0) - 'A';
  char square[3];
  string sq;
  for(int f = file-1; f <= file+1; f++){
    for(int r = rank-1; r <= rank+1; r++){
      // not the same as source_square
      if(f != file || r != rank){
        if(r <= RANK_8 && r >= RANK_1 && f <= FILE_H && f >= FILE_A){
            // If the square is empty or piece of different color
            if((board[r][f] == NULL) || (board[r][f] != NULL && board[rank][file]->getIsWhite() != board[r][f]->getIsWhite())){
              square[0] = f + 'A';
              square[1] = r + '1';
              square[2] = '\0';
              sq = square;
              possible_moves.push_back(sq);
              // cout << "square " << square << endl;
            }
        }
      }
    }
  }
}

void Piece::calculateLShapePossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves){
  int rank = source_square.at(1) - '1';
  int file = source_square.at(0) - 'A';
  bool is_white = board[rank][file]->getIsWhite();
  char square[3];
  string sq;
  for(int f = file -2; f <= file + 2; f++){
    if(f >= FILE_A && f <= FILE_H){
      for(int r = rank -2; r <= rank + 2; r++){
        if(r >= RANK_1 && r <= RANK_8){
          if(((abs(f - file) == 2) && (abs(r - rank) == 1)) || ((abs(f - file) == 1) && (abs(r - rank) == 2))){
            if(board[r][f] == NULL || (board[r][f] == NULL && is_white != board[r][f]->getIsWhite())){
              square[0] = f + 'A';
              square[1] = r + '1';
              square[2] = '\0';
              sq = square;
              possible_moves.push_back(sq);
              // cout << "square " << sq << endl;
            }
          }
        }
      }
    }
  }
}

void Piece::calculatePawnPossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves){
  int rank = source_square.at(1) - '1';
  int file = source_square.at(0) - 'A';
  bool is_white = board[rank][file]->getIsWhite();
  char square[3];
  string sq;
  // White pawn move forward up
  if(is_white && rank < RANK_8){
    if(is_first_move_ && (board[rank+1][file] == NULL) &&(board[rank+2][file] == NULL) ){
      square[0] = file  + 'A';
      square[1] = rank + 2 + '1';
      square[2] = '\0';
      sq = square;
      possible_moves.push_back(sq);
    }
    if(board[rank+1][file] == NULL){
      square[0] = file  + 'A';
      square[1] = rank + 1 + '1';
      square[2] = '\0';
      sq = square;
      possible_moves.push_back(sq);
    }

    // If there is a black piece in the diagonal forward
    if((file < FILE_H) && (board[rank+1][file+1] != NULL) && (!board[rank+1][file+1]->getIsWhite())){
      square[0] = file + 1  + 'A';
      square[1] = rank + 1 + '1';
      square[2] = '\0';
      sq = square;
      possible_moves.push_back(sq);
    }
    if((file > FILE_A) && (board[rank+1][file-1] != NULL) && !board[rank+1][file-1]->getIsWhite()){
      square[0] = file -1 + 'A';
      square[1] = rank + 1 + '1';
      square[2] = '\0';
      sq = square;
      possible_moves.push_back(sq);
    }
  }
  // Black pawn move forward down
  else if(!is_white && rank > RANK_1){
    if(is_first_move_ && (board[rank-1][file] == NULL) &&(board[rank-2][file] == NULL)){
      square[0] = file  + 'A';
      square[1] = rank - 2 + '1';
      square[2] = '\0';
      sq = square;
      possible_moves.push_back(sq);
    }
    if(board[rank-1][file] == NULL){
      square[0] = file  + 'A';
      square[1] = rank - 1 + '1';
      square[2] = '\0';
      sq = square;
      possible_moves.push_back(sq);
    }

    // If there is a white piece in the diagonal forward
    if((file > FILE_A) && (board[rank-1][file-1] != NULL) && (!board[rank-1][file-1]->getIsWhite())){
      square[0] = file - 1  + 'A';
      square[1] = rank - 1 + '1';
      square[2] = '\0';
      sq = square;
      possible_moves.push_back(sq);
    }
    if((file < FILE_H) && (board[rank-1][file+1] != NULL) && !board[rank-1][file+1]->getIsWhite()){
      square[0] = file +1 + 'A';
      square[1] = rank - 1 + '1';
      square[2] = '\0';
      sq = square;
      possible_moves.push_back(sq);
    }
  }
}

bool Piece::isKingSafe(const string king_position, Piece* board[8][8]){
  int rank = king_position.at(1) - '1';
  int file = king_position.at(0) - 'A';
  bool is_white = board[rank][file]->getIsWhite();
  // Check diagonal lines and see if there is opponent Queen or Bishop

  // TODO Change it to ternary operator
  // if(is_white){
  //   check
  // }

  // Check vertical lines to the top
  bool is_blocking = false;

  // Check north east diagonal
  int r = rank+1;
  for(int f = file+1; f <= FILE_H; f++){
    if(!isKingSafeQueenBishop(r, f, is_white, is_blocking, board)){
      // cout << "king is in check from north east" << endl;
      return false;
    }
    r++;
  }

  // Check south east diagonal
  is_blocking = false;
  r = rank-1;
  for(int f = file+1; f <= FILE_H; f++){
    if(!isKingSafeQueenBishop(r, f, is_white, is_blocking, board)){
      return false;
    }
    r--;
  }

  // Check north west diagonal
  is_blocking = false;
  r = rank+1;
  for(int f = file-1; f >= FILE_A; f--){
    if(!isKingSafeQueenBishop(r, f, is_white, is_blocking, board)){
      return false;
    }
    r++;
  }

  // Check south west diagonal
  is_blocking = false;
  r = rank-1;
  for(int f = file-1; f >= FILE_A; f--){
    if(!isKingSafeQueenBishop(r, f, is_white, is_blocking, board)){
      return false;
    }
    r--;
  }

  // Check vertical line to the top
  is_blocking = false;
  for(int r = rank+1; r <= RANK_8; r++){
    if(!isKingSafeQueenRook(r, file, is_white, is_blocking, board)){
      return false;
    }
  }
  // Check vertical line to the bottom
  is_blocking = false;
  for(int r = rank-1; r >= RANK_1; r--){
    if(!isKingSafeQueenRook(r, file, is_white, is_blocking, board)){
      return false;
    }
  }

  // Check horizontal line to the right
  is_blocking = false;
  for(int f = file+1; f <= FILE_H; f++){
    // cout << "heiing" << endl;
    if(!isKingSafeQueenRook(rank, f, is_white, is_blocking, board)){
      return false;
    }
  }

  // Check horizontal line to the left
  is_blocking = false;
  for(int f = file -1; f >= FILE_A; f--){
    if(!isKingSafeQueenRook(rank, f, is_white, is_blocking, board)){
      return false;
    }
  }

  // Check if the opponent's King is threatening to attack
  for(int f = file-1; f <= file+1; f++){
    for(int r = rank-1; r <= rank+1; r++){
      if(is_white && board[r][f] != nullptr && board[r][f]->getSimbol() == "BK"){
        return false;
      }
      else if(!is_white && board[r][f]->getSimbol() == "WK"){
        return false;
      }
    }
  }

  // Check if opponent pawn is threatening to attack
  // TODO double check if file range is correct
  if(is_white && rank < RANK_8 && file < FILE_H && file > FILE_A){
    if(board[rank+1][file+1]->getSimbol() == "BP" || board[rank+1][file-1]->getSimbol() == "BP"){
      return false;
    }
  }
  else if(!is_white && rank > RANK_1 && file < FILE_H && file > FILE_A){
    if(board[rank-1][file-1]->getSimbol() == "WP" || board[rank-1][file+1]->getSimbol() == "WP"){
      return false;
    }
  }

  return true;
}

// TODO Super redundant here
bool Piece::isKingSafeQueenBishop( int rank, int file, bool is_white, bool& is_blocking, Piece* board[8][8]){
  if(board[rank][file] != nullptr && is_white && !board[rank][file]->getIsWhite()){
    // Check if there is any blocking piece
    if(board[rank][file] != nullptr && is_white && board[rank][file]->getIsWhite()){
      is_blocking = true;
    }
    // If no blocking, and find black queen and bishop, then white King is not safe
    if( !is_blocking && (board[rank][file]->getSimbol() == "BQ" || board[rank][file]->getSimbol() == "BB")){
      return false;
    }
  }

  // TODO Super redundant here, do something to fix it!!
  // Check if white king is threaten by black Queen or Rook
  if(board[rank][file] != nullptr && !is_white && board[rank][file]->getIsWhite()){
    // Check if there is any blocking piece
    if(board[rank][file] != nullptr && !is_white && !board[rank][file]->getIsWhite()){
      is_blocking = true;
    }
    // If no blocking, and find black queen and bishop, then white King is not safe
    if( !is_blocking && (board[rank][file]->getSimbol() == "WQ" || board[rank][file]->getSimbol() == "WB")){
      return false;
    }
  }
  return true;

}
bool Piece::isKingSafeQueenRook( int rank, int file, bool is_white, bool& is_blocking, Piece* board[8][8]){
  // Check if white king is threaten by black Queen or Rook
  if(board[rank][file] != nullptr && is_white && !board[rank][file]->getIsWhite()){
    // Check if there is any blocking piece
    if(board[rank][file] != nullptr && is_white && board[rank][file]->getIsWhite()){
      is_blocking = true;
    }
    // If no blocking, and find black queen and bishop, then white King is not safe
    if( !is_blocking && (board[rank][file]->getSimbol() == "BQ" || board[rank][file]->getSimbol() == "BR")){
      return false;
    }
  }

  // TODO Super redundant here, do something to fix it!!
  // Check if white king is threaten by black Queen or Rook
  if(board[rank][file] != nullptr && !is_white && board[rank][file]->getIsWhite()){
    // Check if there is any blocking piece
    if(board[rank][file] != nullptr && !is_white && !board[rank][file]->getIsWhite()){
      is_blocking = true;
    }
    // If no blocking, and find black queen and bishop, then white King is not safe
    if( !is_blocking && (board[rank][file]->getSimbol() == "WQ" || board[rank][file]->getSimbol() == "WR")){
      return false;
    }
  }
  return true;
}
