#ifndef PIECE_H
#define PIECE_H

class Piece{
protected:
  
public:
  Piece();
  // Can jump
  virtual bool isValidMove() = 0;
};

#endif
