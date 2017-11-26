#ifndef KING_H
#define KING_H

#include "Piece.h"
#include "Definitions.h"

class King: public Piece{
private:

public:
virtual bool isValidMove();

// castling();
};

#endif
