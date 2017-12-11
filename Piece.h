#ifndef PIECE_H
#define PIECE_H
#include <string>
#include <vector>
using namespace std;

class Piece{
private:

protected:
  bool is_white_;
  bool is_first_move_;
public:
  Piece(bool white);
  virtual ~Piece();
  bool isValidMove(const string source_square, \
                   const string destination_square, \
                   Piece* board[8][8]);

  virtual void calculatePossibleMove(string source_square, Piece* board[8][8], \
                                     vector<string>& possible_moves) = 0;

  bool isDestinationEmpty(int rank, int file, bool is_white, Piece* board[8][8], \
                   vector<string>& possible_moves);
  void calculateVerticalPossibleMove(const string source_square, \
                                     Piece* board[8][8], \
                                     vector<string>& possible_moves);
  void calculateHorizontalPossibleMove(const string source_square, \
                                       Piece* board[8][8], \
                                       vector<string>& possible_moves);
  void calculateDiagonalPossibleMove(const string source_square, \
                                     Piece* board[8][8], \
                                     vector<string>& possible_moves);

  virtual string getString() = 0;
  virtual string getSimbol() = 0;
  bool isWhite();
  bool isFirstMove();
  void negateIsFirstMove();
};

#endif
