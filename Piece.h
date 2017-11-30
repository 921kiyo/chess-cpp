#ifndef PIECE_H
#define PIECE_H
#include <string>

using namespace std;

class Piece{
protected:
  bool is_white_;
public:
  Piece(bool white);
  // Can jump
  virtual ~Piece();
  virtual bool isValidMove() = 0;
  virtual string getSimbol() = 0;
};

#endif
