#ifndef CHESSBOARD_H
#define CHESSBOARD_H

class ChessBoard {
private:
  bool is_white_turn;
public:
  ChessBoard();
  void submitMove(const char* source_square, const char* destination_square);
  bool isWhiteTurn();
  void resetBoard();
};

#endif
