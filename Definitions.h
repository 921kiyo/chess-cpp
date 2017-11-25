#ifndef DEFINITION_H
#define DEFINITION_H

// unsigned long long is needed, otherwise it would interpret it as 32 bit
typedef unsigned long long bit_64;

const int BOARD_SQUARE_SIZE = 120;
// const long long U64;

enum PieceEnum {
  empty,
  white_pawn,
  white_knight,
  white_bishop,
  white_rook,
  white_queen,
  white_king,
  black_pawn,
  black_knight,
  black_bishop,
  black_rook,
  black_queen,
  black_king
};

enum FileEnum {
  file_a,
  file_b,
  file_c,
  file_d,
  file_e,
  file_f,
  file_g,
  file_h,
  file_none
};

enum RankEnum {
  rank_1,
  rank_2,
  rank_3,
  rank_4,
  rank_5,
  rank_6,
  rank_7,
  rank_8,
  rank_none
};

enum ColorEnum{
  white,
  black,
  // Do I need this?
  both
};

enum BoardEnum {
  A1 = 21, B1, C1, D1, E1, F1, G1, H1,
  A2 = 31, B2, C2, D2, E2, F2, G2, H2,
  A3 = 41, B3, C3, D3, E3, F3, G3, H3,
  A4 = 51, B4, C4, D4, E4, F4, G4, H4,
  A5 = 61, B5, C5, D5, E5, F5, G5, H5,
  A6 = 71, B6, C6, D6, E6, F6, G6, H6,
  A7 = 81, B7, C7, D7, E7, F7, G7, H7,
  A8 = 91, B8, C8, D8, E8, F8, G8, H8, No_Sq // No_Sq means off board
};


// C++ 11 Enum class
// Should this be capitalized??
// enum class PieceEnum {
//   empty,
//   white_pawn,
//   white_knight,
//   white_bishop,
//   white_rook,
//   white_queen,
//   white_king,
//   black_pawn,
//   black_knight,
//   black_bishop,
//   black_rook,
//   black_queen,
//   black_king
// };
//
// enum class FileEnum {
//   file_a,
//   file_b,
//   file_c,
//   file_d,
//   file_e,
//   file_f,
//   file_g,
//   file_h,
//   file_none
// };
//
// enum class RankEnum {
//   rank_1,
//   rank_2,
//   rank_3,
//   rank_4,
//   rank_5,
//   rank_6,
//   rank_7,
//   rank_8,
//   rank_none
// };
//
// enum class ColorEnum{
//   white,
//   black,
//   // Do I need this?
//   both
// };
//
// enum class BoardEnum {
//   A1 = 21, B1, C1, D1, E1, F1, G1, H1,
//   A2 = 31, B2, C2, D2, E2, F2, G2, H2,
//   A3 = 41, B3, C3, D3, E3, F3, G3, H3,
//   A4 = 51, B4, C4, D4, E4, F4, G4, H4,
//   A5 = 61, B5, C5, D5, E5, F5, G5, H5,
//   A6 = 71, B6, C6, D6, E6, F6, G6, H6,
//   A7 = 81, B7, C7, D7, E7, F7, G7, H7,
//   A8 = 91, B8, C8, D8, E8, F8, G8, H8, No_Sq // No_Sq means off board
// };

#define get_120_square_version(file, rank) ( 21 + file + rank * 10)



#endif
