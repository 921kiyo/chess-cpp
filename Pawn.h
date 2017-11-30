#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
#include "Definitions.h"

class Pawn: public Piece{
private:

public:
Pawn(bool white);
virtual bool isValidMove();

// castling();
};

#endif
