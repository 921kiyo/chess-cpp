#ifndef CHESSBOARD_H
#define CHESSBOARD_H

// #define DEBUG
// #ifndef DEBUG
// #define ASSERT(n)
// #else
// #define ASSERT(n)
// if(!(n)){
//   printf("%s - failed", #n);
//   printf("In File %s ",__FILE__);
//   printf("At Line %d\n", __LINE__);
//   exit(1);
// }
// #endif

#include "Definitions.h"

class ChessBoard {
private:
  bool is_white_turn;
  int number_of_piece[13];

  int square_120[BOARD_SQUARE_SIZE]{120};
  int square_64[64]{65};

  int pieces[BOARD_SQUARE_SIZE];
  bit_64 pawns[3]; // White, black and botg

  bit_64 position_id;

  int king_square[2];

  int side; // current side to move

  // Fifty move necessary ??

  // Used for draw on endgame etc.
  int big_piece[3]; // anything that is not a pawn

  int piece_list[13][10]; // ??
public:
  ChessBoard();
  void submitMove(const char* source_square, const char* destination_square);
  bool isWhiteTurn();
  void resetBoard();
  int get_120_square_version(int file, int rank);
  void printBoard();
  void printBitBoard(bit_64 bit_board);

  // void first_move();

  // is_checkmate();

  // Check if the king is in check
  // in_check
};

#endif
