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

#include <string>

using namespace std;

#include "Definitions.h"

class ChessBoard {
private:
  bool is_white_turn_;
  // int board_[FILE_none+2][RANK_none+4];
  int board_[FILE_NONE][RANK_NONE];
public:
  ChessBoard();
  void submitMove(const char* source_square, const char* destination_square);
  bool isWhiteTurn();
  void resetBoard();
  void printCurrentBoard();
  string convertIntToPiece(int& num);
  void make_move(const char* source_square, const char* destination_square);
};

#endif
