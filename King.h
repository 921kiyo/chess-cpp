#ifndef KING_H
#define KING_H

#include "Piece.h"
#include "Definitions.h"
#include <string>

using namespace std;

class King: public Piece{
private:

public:
King(bool white);
virtual ~King();
virtual bool isValidMove();
virtual string getSimbol();
// void calculatePossibleMove(int rank, int file, int board);
// bool isKingSafe();
// castling();
};

#endif
