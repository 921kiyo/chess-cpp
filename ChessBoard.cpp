#ifndef CHESSBOARD_H
#define CHESSBOARD_H

class ChessBoard {
private:
public:
  void submitMove(const char* source_square, const char* destination_square);
  void resetBoard();
};

#endif
