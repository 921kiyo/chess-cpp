#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
#include "Definitions.h"
#include <string>

using namespace std;

class Pawn: public Piece{
private:

public:
Pawn(bool white);
virtual bool isValidMove();
virtual string getSimbol();
// castling();
};

#endif
