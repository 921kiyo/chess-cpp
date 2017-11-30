#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"
#include "Definitions.h"
#include <string>

using namespace std;

class Knight: public Piece{
private:

public:
Knight(bool white);
virtual bool isValidMove();
virtual string getSimbol();
void calculatePossibleMove(int rank, int file, int board);

};
// virtual ~Knight();


#endif
