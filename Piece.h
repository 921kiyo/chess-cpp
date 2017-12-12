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
  virtual void calculatePossibleMove(const string source_square, \
                                     shared_ptr<Piece> board[][BOARD_LENGTH], \
                                     vector<string>& possible_moves) = 0;

  // Helper method for the below 3 calculateXXPossibleMove() to check
  // if the piece can still continue to move forward
  bool canMoveForward(int rank, int file, bool is_white, \
                          shared_ptr<Piece> board[][BOARD_LENGTH], \
                          vector<string>& possible_moves);

  // check all the vertical squares from source_square and
  // update possible_moves vector
  void calculateVerticalPossibleMove(const string source_square, \
                                     shared_ptr<Piece> board[][BOARD_LENGTH], \
                                     vector<string>& possible_moves);
   // check all the horizontal squares from source_square and
   // update possible_moves vector
  void calculateHorizontalPossibleMove(const string source_square, \
                                       shared_ptr<Piece> board[][BOARD_LENGTH], \
                                       vector<string>& possible_moves);
  // check all the diagonal squares from source_square and
  // update possible_moves vector
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
