#ifndef PIECE_H
#define PIECE_H

#include "Helper.h"

#include <string>
#include <vector>
#include <memory>

using namespace std;

class Piece{
protected:
  bool is_white_;
  bool is_first_move_;

  // calculate all possible moves given the current position
  // of pieces for each piece
  virtual void calculatePossibleMove(string source_square, \
                                     shared_ptr<Piece> board[][BOARD_LENGTH], \
                                     vector<string>& possible_moves) = 0;

  bool isDestinationEmpty(int rank, int file, bool is_white, \
                          shared_ptr<Piece> board[][BOARD_LENGTH], \
                          vector<string>& possible_moves);
  void calculateVerticalPossibleMove(const string source_square, \
                                     shared_ptr<Piece> board[][BOARD_LENGTH], \
                                     vector<string>& possible_moves);
  void calculateHorizontalPossibleMove(const string source_square, \
                                       shared_ptr<Piece> board[][BOARD_LENGTH], \
                                       vector<string>& possible_moves);
  void calculateDiagonalPossibleMove(const string source_square, \
                                     shared_ptr<Piece> board[][BOARD_LENGTH], \
                                     vector<string>& possible_moves);
public:
  Piece(bool white);
  // Call calculatePossibleMove() and check if destination_square is
  // in the possible move vector. If so, return true. Otherwise, return false.
  bool isValidMove(const string source_square, \
                   const string destination_square, \
                   shared_ptr<Piece> board[][BOARD_LENGTH]);



  bool isWhite();
  bool isFirstMove();
  void negateIsFirstMove();
  virtual string getString() = 0;
  virtual string getSimbol() = 0;
};

#endif
