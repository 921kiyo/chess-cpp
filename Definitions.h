#ifndef DEFINITION_H
#define DEFINITION_H

#include <cstdint>

// Delete this
// enum PieceEnum {
//   EMPTY,
//   W_pawn,
//   W_rook,
//   W_knight,
//   W_bishop,
//   W_queen,
//   W_king,
//   B_pawn,
//   B_rook,
//   B_knight,
//   B_bishop,
//   B_queen,
//   B_king
// };

enum FileEnum {
  FILE_A,
  FILE_B,
  FILE_C,
  FILE_D,
  FILE_E,
  FILE_F,
  FILE_G,
  FILE_H,
  FILE_NONE
};

enum RankEnum {
  RANK_1,
  RANK_2,
  RANK_3,
  RANK_4,
  RANK_5,
  RANK_6,
  RANK_7,
  RANK_8,
  RANK_NONE
};

#endif
