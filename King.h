#ifndef KING_H
#define KING_H

#include "Piece.h"
#include "Definitions.h"

class King: public Piece{
private:

public:
King();
virtual ~King();
virtual bool isValidMove();
void calculatePossibleMove(int rank, int file, int board);
bool isKingSafe();
// castling();
};

#endif
