#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "Definitions.h"
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
  Piece* board_[FILE_NONE][RANK_NONE];

  bool is_white_in_check_;
  bool is_black_in_check_;
  // What is the difference if this was type King??
  Piece* white_king_ptr_;
  Piece* black_king_ptr_;
  string white_king_position_;
  string black_king_position_;
  string attacking_piece_position_;
  // Double check
  string attacking_piece_position2;
  Piece* pre_pre_dest_square_;
  Piece* previous_destination_square_;

public:
  ChessBoard();
  ~ChessBoard();
  void cleanBoard();
  bool isValidSquare(const string square);
  void submitMove(const string source_square, const string destination_square);
  bool isWhiteTurn();
  void resetBoard();
  void printCurrentBoard();
  void undoMove(string source_square, string destination_square);
  void updateKingPosition(Piece* piece_ptr, string piece_square);
  bool isKingSafe();
  // TODO add const
  void makeMove(string source_square, string destination_square);
  Piece* getPiecePtrFromBoard(const string source_square);
  void getKingPosition(const int king_enum, char* king_position);
  bool isPossibleMoveLeft();
  bool isCheckMate();
};

#endif
