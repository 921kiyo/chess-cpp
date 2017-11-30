#ifndef PIECE_H
#define PIECE_H

class Piece{
protected:
  bool is_white_;
public:
  Piece(bool white);
  // Can jump
  virtual ~Piece();
  virtual bool isValidMove() = 0;
};

#endif
