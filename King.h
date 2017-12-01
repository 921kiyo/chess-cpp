#ifndef KING_H
#define KING_H

#include "Piece.h"
#include "Definitions.h"
#include <string>
#include <vector>

using namespace std;

class King: public Piece{
private:

public:
King(bool white);
virtual ~King();
// virtual bool isValidMove();
virtual string getSimbol();
virtual void calculatePossibleMove(const string source_square, Piece* board[8][8], vector<string>& possible_moves);
// void isValidMove(const char* source_square, const char* destination_square, Piece* board);
// bool isKingSafe();
// castling();
};

#endif
