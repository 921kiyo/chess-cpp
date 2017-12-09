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
  bool isValidMove(const string source_square, const string destination_square, Piece* board[8][8]);

  // Used for Queen, Rook, Bishop possible moves
  virtual void calculatePossibleMove(string source_square, Piece* board[8][8], vector<string>& possible_moves) = 0;
  bool checkSquare(int rank, int file, bool is_white, Piece* board[8][8], vector<string>& possible_moves);
  void calculateVerticalPossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves);
  void calculateHorizontalPossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves);
  void calculateDiagonalPossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves);

  // Used for King possible moves
  void calculateAdjacentPossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves);

  // Used for Knight possible moves
  void calculateLShapePossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves);

  // Used for Pawn possible moves
  void calculatePawnPossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves);

  virtual string getSimbol() = 0;
  // TODO Should be called isWhite?
  bool getIsWhite();
  void negateIsFirstMove();
};

#endif
