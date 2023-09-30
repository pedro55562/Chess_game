#ifndef ROOK_H
#define ROOK_H

#include "Chess_constants.h"
#include "Piece.h"

class Rook : public Piece{
public:
    Rook(int RookColor);
    bool isValidMove(int fromX, int fromY, int toX, int toY) const;    

};

#endif