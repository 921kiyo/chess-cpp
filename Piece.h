#ifndef PIECE_H
#define PIECE_H
#include <string>
#include <vector>
using namespace std;

class Piece{
protected:
  bool is_white_;
  bool is_first_move_;
public:
  Piece(bool white);
  virtual ~Piece();
  bool isValidMove(const string source_square, const string destination_square, Piece* board[8][8]);

  // Used for Queen possible moves
  virtual void calculatePossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves) = 0;
  bool checkSquare(int rank, int file, bool is_white, Piece* board[8][8], vector<string>& possible_moves);
  void calculateVerticalPossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves);
  void calculateHorizontalPossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves);
  void calculateDiagonalPossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves);

  virtual string getSimbol() = 0;
  bool getIsWhite();
  void negateIsFirstMove();
  bool isKingSafe(const string king_positions);
};

#endif
