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
#include <vector>
#include <memory>

using namespace std;

class ChessBoard {
private:
  bool is_white_turn_;
  bool is_game_finished;
  shared_ptr<Piece> board_[FILE_NONE][RANK_NONE];

  bool is_white_in_check_;
  bool is_black_in_check_;
  shared_ptr<Piece> white_king_ptr_;
  shared_ptr<Piece> black_king_ptr_;
  string white_king_position_;
  string black_king_position_;
  shared_ptr<Piece> previous_destination_square_;

public:
  ChessBoard();
  bool isValidInput(const string square);
  void submitMove(const string source_square, const string destination_square);
  void resetBoard();
  void printCurrentBoard();
  void undoMove(string source_square, string destination_square);
  void updateKingPosition(shared_ptr<Piece> piece_ptr, string piece_square);
  shared_ptr<Piece> getPiecePtrFromBoard(const string source_square);
  bool isNoPieceBetweenKingRook(string king_position, string rook_position);
  string getRookPosition(string destination_square);
  bool checkCastling(const string source_square, const string destination_square);
  void moveRookCastling(string rook_position);
  bool isKingSafeWhileCastling(const string source_square, const string destination_square);
  bool isKingSafe(bool my_king);
  // TODO add const
  void makeMove(string source_square, string destination_square);
  bool isPossibleMoveLeft();
};

#endif
