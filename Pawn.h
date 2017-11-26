#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
#include "Definitions.h"

class Pawn: public Piece{
private:

public:
virtual bool isValidMove();

// castling();
};

#endif
