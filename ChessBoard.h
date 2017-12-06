#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "Definitions.h"
#include "Piece.h"
#include "King.h"

#include <string>
#include <map>
#include <vector>

using namespace std;

class ChessBoard {
private:
  bool is_white_turn_;
  Piece* board_[FILE_NONE][RANK_NONE];
  // What is the difference if this was type King??
  bool is_white_in_check_;
  bool is_black_in_check_;
  Piece* white_king_;
  Piece* black_king_;
  string white_king_position_;
  string black_king_position_;
  Piece* previous_destination_square_;

public:
  ChessBoard();
  ~ChessBoard();
  void submitMove(const string source_square, const string destination_square);
  bool isWhiteTurn();
  void updateWhiteKingPtr(Piece* wk);
  void updateBlackKingPtr(Piece* bk);
  void updateWhiteKingPosition(string wk);
  void updateBlackKingPosition(string bk);
  void resetBoard();
  void printCurrentBoard();
  void undoMove(string source_square, string destination_square);
  // TODO add const
  void makeMove(string source_square, string destination_square);
  Piece* getPieceFromBoard(const string source_square);
  void getKingPosition(const int king_enum, char* king_position);
  void calculatePossibleMoveToSaveKing(vector<string>&possible_moves);
  bool isCheckMate();
};

#endif
