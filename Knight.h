#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"
#include "Definitions.h"

class Knight: public Piece{
private:

public:
virtual bool isValidMove();
void calculatePossibleMove(int rank, int file, int board);

};
// virtual ~Knight();


#endif
