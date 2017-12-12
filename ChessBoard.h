#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "Helper.h"
#include "Piece.h"
#include "Pawn.h"
#include "Queen.h"
#include "King.h"
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
  shared_ptr<Piece> board_[BOARD_LENGTH][BOARD_LENGTH];

  bool is_white_in_check_;
  bool is_black_in_check_;
  shared_ptr<Piece> white_king_ptr_;
  shared_ptr<Piece> black_king_ptr_;
  string white_king_position_;
  string black_king_position_;
  shared_ptr<Piece> previous_destination_square_;

public:
  ChessBoard();
  // Make the intial chess board in board_[8][8]
  void resetBoard();
  // Check if square is within the board range
  bool isValidInput(const string square);
  // Helper method to get an pointer from the board
  shared_ptr<Piece> getPiecePtrFromBoard(const string source_square);

  void submitMove(const string source_square, const string destination_square);
  // TODO add const
  void makeMove(string source_square, string destination_square);
  void undoMove(string source_square, string destination_square);
  bool isKingSafe(bool my_king);
  // Update kings position and pointer if the piece you moved is a king
  void updateKingPosition(shared_ptr<Piece> piece_ptr, string piece_square);

  // Check all the pieces in the board, and see if there is any valid move left
  bool isPossibleMoveLeft();
  // Given a starting square, loop through the board and check if there is
  // any valid move left, given that the king is safe.
  // This method is called inside isPossibleMoveLeft()
  bool isPossibleDestinationLeft(int source_file, int source_rank);

  bool canGameContinue();
  // TODO Delete this
  void printCurrentBoard();

  // Below methods are for castling
  bool isNoPieceBetweenKingRook(string king_position, string rook_position);
  string getRookPosition(string destination_square);
  bool checkCastling(const string source_square, const string destination_square);
  void moveRookCastling(string rook_position);
  bool isKingSafeWhileCastling(const string source_square, const string destination_square);
};

#endif
