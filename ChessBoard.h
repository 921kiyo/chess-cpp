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
  // Check inputs are valid, and execute makeMove(), swap the player's turn
  // Also check if the game is in check, checkmate or stalemate
  void submitMove(const string source_square, const string destination_square);
  void makeMove(const string source_square, const string destination_square);
  void undoMove(const string source_square, const string destination_square);
  // Check if opponent king is in check and update status
  void checkKingStatus();
  // return true if King is safe. Argument my_king determines whether
  // you want to check your own king (my_king=true)
  // or opponent king (my_king=false). If in check, return falase
  bool isKingSafe(bool my_king);
  // Update kings position and pointer if the piece you moved is a king
  void updateKingPosition(shared_ptr<Piece> piece_ptr, const string piece_square);

  // Check all the pieces in the board, and see if there is any valid move left
  bool isPossibleMoveLeft();
  // Given a starting square, loop through the board and check if there is
  // any valid move left, given that the king is safe.
  // This method is called inside isPossibleMoveLeft()
  bool isPossibleDestinationLeft(int source_file, int source_rank);

  // Check if either king is in checkmate or stalemate.
  // If so, the game cannot continue unless reset
  bool canGameContinue();

  // Below methods are used for castling

  bool isNoPieceBetweenKingRook(const string king_position, \
                                const string rook_position);
  // Helper method to get Rook position based on
  // King's castling destination square
  string getRookPosition(const string destination_square);
  // Execute the castling move for King and Rook after check all the conditions
  bool isCastling(const string source_square, const string destination_square);
  // Move rook in castling
  void moveRookCastling(string rook_position);
  // Move King while check if the king does not pass through a square
  // that is attacked by opponent pieces
  bool isKingSafeWhileCastling(const string source_square, \
                               const string destination_square, \
                               int first, int second);
};

#endif
