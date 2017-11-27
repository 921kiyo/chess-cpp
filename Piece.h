#ifndef PIECE_H
#define PIECE_H

class Piece{
protected:

public:
  Piece();
  // Can jump
  virtual ~Piece();
  virtual bool isValidMove() = 0;
};

#endif
