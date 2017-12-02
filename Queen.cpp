#include "Queen.h"
#include "Piece.h"
#include "Definitions.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Queen::Queen(bool white): Piece(white){
}

Queen::~Queen(){}

// bool Queen::isValidMove(){
//
// }
void Queen::calculatePossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves){
  calculateVerticalPossibleMove(source_square, board, possible_moves);
  calculateHorizontalPossibleMove(source_square, board, possible_moves);
  calculateDiagonalPossibleMove(source_square, board, possible_moves);
}
void Queen::calculateVerticalPossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves){
  int rank = source_square.at(1) - '1';
  int file = source_square.at(0) - 'A';
  char square[3];
  string sq;
  // Check vertical lines to the top
  for(int r = rank+1; r <= RANK_8; r++){
    if(board[r][file] != NULL && board[rank][file]->getIsWhite() == board[r][file]->getIsWhite()){
      break;
    }
    else if(board[r][file] != NULL && board[rank][file]->getIsWhite() != board[r][file]->getIsWhite()){
      square[0] = r + '1';
      square[1] = source_square.at(0);
      square[2] = '\0';
      sq = square;
      possible_moves.push_back(sq);
      cout << "square1 " << square << endl;
      break;
    }
    else if(board[r][file] == NULL){
       square[0] = r + '1';
       square[1] = source_square.at(0);
       square[2] = '\0';
       sq = square;
       possible_moves.push_back(sq);
       cout << "square1 " << square << endl;
    }
  }
  // Check vertical line to the bottom
  for(int r = rank-1; r >= RANK_1; r--){
    if(board[r][file] != NULL && board[rank][file]->getIsWhite() == board[r][file]->getIsWhite()){
      break;
    }
    if(board[r][file] != NULL && board[rank][file]->getIsWhite() != board[r][file]->getIsWhite()){
      square[0] = r + '1';
      square[1] = source_square.at(0);
      square[2] = '\0';
      sq = square;
      possible_moves.push_back(sq);
      break;
    }
    else if(board[r][file] == NULL){
      square[0] = r + '1';
      square[1] = source_square.at(0);
      square[2] = '\0';
      sq = square;
      possible_moves.push_back(sq);
      cout << "square2 " << square << endl;
    }
  }
}

void Queen::calculateHorizontalPossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves){
  int rank = source_square.at(1) - '1';
  int file = source_square.at(0) - 'A';
  char square[3];
  string sq;
  // Check horizontal lines to the right
  for(int f = file+1; f <= FILE_H; f++){
    if(board[rank][f] != NULL && board[rank][f]->getIsWhite() == board[rank][f]->getIsWhite()){
      break;
    }
    else if (board[rank][f] != NULL && board[rank][f]->getIsWhite() != board[rank][f]->getIsWhite()){
      square[0] = source_square.at(1);
      square[1] = f + 'A';
      square[2] = '\0';
      sq = square;
      possible_moves.push_back(sq);
      break;
    }
    else if(board[rank][f] == NULL){
      square[0] = source_square.at(1);
      square[1] = f + 'A';
      square[2] = '\0';
      sq = square;
      possible_moves.push_back(sq);
      cout << "square3 " << square << endl;
    }
  }

  // Check horizontal lines to the left
  for(int f = file-1; f >= FILE_A; f--){
    if(board[rank][f] != NULL && board[rank][f]->getIsWhite() == board[rank][f]->getIsWhite()){
      break;
    }
    else if(board[rank][f] != NULL && board[rank][f]->getIsWhite() != board[rank][f]->getIsWhite()){
      square[0] = source_square.at(1);
      square[1] = f + 'A';
      square[2] = '\0';
      sq = square;
      possible_moves.push_back(sq);
      cout << "square3 " << square << endl;
      break;
    }
    else if(board[rank][f] == NULL){
      square[0] = source_square.at(1);
      square[1] = f + 'A';
      square[2] = '\0';
      sq = square;
      possible_moves.push_back(sq);
      cout << "square3 " << square << endl;
    }
  }
}

void Queen::calculateDiagonalPossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves){
  int rank = source_square.at(1) - '1';
  int file = source_square.at(0) - 'A';
  char square[3];
  string sq;
  // Check giagonal lines
  int r = rank+1;
  for(int f = file+1; f <= FILE_H; f++){
      if(r < RANK_1 || r > RANK_8){
        break;
      }
      else if(board[r][f] != NULL && board[r][f]->getIsWhite() == board[r][f]->getIsWhite()){
        break;
      }
      if(board[r][f] != NULL && board[r][f]->getIsWhite() != board[r][f]->getIsWhite()){
        square[0] = r + '1';
        square[1] = f + 'A';
        square[2] = '\0';
        sq = square;
        possible_moves.push_back(sq);
        cout << "square diagonal 1 " << square << endl;
        break;
      }
      else if(board[r][f] == NULL){
        square[0] = r + '1';
        square[1] = f + 'A';
        square[2] = '\0';
        sq = square;
        possible_moves.push_back(sq);
        cout << "square diagonal 1 " << square << endl;
      }
      r++;
  }
  // // Reset r
  r = rank-1;
  for(int f = file+1; f <= FILE_H; f++){
      if(r < RANK_1 || r > RANK_8){
        break;
      }
      else if(board[r][f] != NULL && board[r][f]->getIsWhite() == board[r][f]->getIsWhite()){
        break;
      }
      else if(board[r][f] != NULL && board[r][f]->getIsWhite() != board[r][f]->getIsWhite()){
        square[0] = r + '1';
        square[1] = f + 'A';
        square[2] = '\0';
        sq = square;
        possible_moves.push_back(sq);
        cout << "square diagonal 1 " << square << endl;
        break;
      }
      else if(board[r][f] == NULL){
        square[0] = r + '1';
        square[1] = f + 'A';
        square[2] = '\0';
        sq = square;
        possible_moves.push_back(sq);
        cout << "square diagonal 1 " << square << endl;
      }
      r--;
  }

  r = rank+1;
  for(int f = file-1; f >= FILE_A; f--){
      if(r < RANK_1 || r > RANK_8){
        break;
      }
      else if(board[r][f] != NULL && board[r][f]->getIsWhite() == board[r][f]->getIsWhite()){
        break;
      }
      if(board[r][f] != NULL && board[r][f]->getIsWhite() != board[r][f]->getIsWhite()){
        square[0] = r + '1';
        square[1] = f + 'A';
        square[2] = '\0';
        sq = square;
        possible_moves.push_back(sq);
        cout << "square diagonal 1 " << square << endl;
        break;
      }
      else if(board[r][f] == NULL){
        square[0] = r + '1';
        square[1] = f + 'A';
        square[2] = '\0';
        sq = square;
        possible_moves.push_back(sq);
        cout << "square diagonal 1 " << square << endl;
      }
      r++;
  }
  // Reset r
  r = rank-1;
  for(int f = file-1; f >= FILE_A; f--){
      if(r < RANK_1 || r > RANK_8){
        break;
      }
      else if(board[r][f] != NULL && board[r][f]->getIsWhite() == board[r][f]->getIsWhite()){
        break;
      }
      else if(board[r][f] != NULL && board[r][f]->getIsWhite() != board[r][f]->getIsWhite()){
        square[0] = r + '1';
        square[1] = f + 'A';
        square[2] = '\0';
        sq = square;
        possible_moves.push_back(sq);
        cout << "square diagonal 1 " << square << endl;
        break;
      }
      else if(board[r][f] == NULL){
        square[0] = r + '1';
        square[1] = f + 'A';
        square[2] = '\0';
        sq = square;
        possible_moves.push_back(sq);
        cout << "square diagonal 1 " << square << endl;
      }
      r--;
  }
}
bool Queen::isKingSafe(){
  return true;
}

string Queen::getSimbol(){
  if(is_white_){
    return "WQ";
  }
  else{
    return "BQ";
  }
}
