#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "Helper.h"
#include "Pawn.h"
#include "Queen.h"
#include "King.h"
#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"

#include <string>
#include <map>
#include <vector>

using namespace std;

class ChessBoard {
private:
  bool is_white_turn_;
  bool is_game_finished;
  Piece* board_[FILE_NONE][RANK_NONE];

  bool is_white_in_check_;
  bool is_black_in_check_;
  // TODO What is the difference if this was type King??
  Piece* white_king_ptr_;
  Piece* black_king_ptr_;
  string white_king_position_;
  string black_king_position_;
  Piece* previous_destination_square_;

public:
  ChessBoard();
  ~ChessBoard();
  void cleanBoard();
  bool isValidInput(const string square);
  void submitMove(const string source_square, const string destination_square);
  void resetBoard();
  void printCurrentBoard();
  void undoMove(string source_square, string destination_square);
  void updateKingPosition(Piece* piece_ptr, string piece_square);
  Piece* getPiecePtrFromBoard(const string source_square);
  bool isNoPieceBetweenKingRook(string king_position, string rook_position);
  void checkCastling(const string source_square, const string destination_square);
  bool isKingSafe(bool my_king);
  // TODO add const
  void makeMove(string source_square, string destination_square);
  bool isPossibleMoveLeft();
};

#endif
