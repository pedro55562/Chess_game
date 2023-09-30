#ifndef QUEEN_H
#define QUEEN_H

#include "Chess_constants.h"
#include "Piece.h"

class Queen : public Piece{
public:
    Queen(int QueenColor);
    bool isValidMove(int fromX, int fromY, int toX, int toY) const;

};

#endif
