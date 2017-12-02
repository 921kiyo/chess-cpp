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
#include "Piece.h"

#include <string>
#include <map>

using namespace std;

class ChessBoard {
private:
  bool is_white_turn_;
  Piece* board_[FILE_NONE][RANK_NONE];
  // Piece* alive_pieces;

  // TODO Should this be static?
  map<int, Piece*> piece_map_;

public:
  ChessBoard();
  ~ChessBoard();
  // void submitMove(const char* source_square, const char* destination_square);
  void submitMove(const string source_square, const string destination_square);
  bool isWhiteTurn();
  void resetBoard();
  void printCurrentBoard();
  // TODO add const
  void makeMove(string source_square, string destination_square);
  // Piece* getPieceFromBoard(const char* source_square);
  Piece* getPieceFromBoard(const string source_square);
  void getKingPosition(const int king_enum, char* king_position);
};

#endif
