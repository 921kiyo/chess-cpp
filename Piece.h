#ifndef PIECE_H
#define PIECE_H
#include <string>
#include <vector>
using namespace std;

class Piece{
protected:
  bool is_white_;
public:
  Piece(bool white);
  // Can jump
  virtual ~Piece();
  // bool isValidMove(const char* source_square, const char* destination_square, Piece* board[8][8]);
  bool isValidMove(const string source_square, const string destination_square, Piece* board[8][8]);
  // virtual void calculatePossibleMove(const char* source_square, Piece* board[8][8], vector<const char*>& possible_moves) = 0;
  virtual void calculatePossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves) = 0;
  virtual string getSimbol() = 0;
  bool getIsWhite();
};

#endif
