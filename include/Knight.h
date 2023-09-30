#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"
#include "Chess_constants.h"

class Knight : public Piece{
    public:
        
        Knight(int KingColor);
        bool isValidMove(int fromX, int fromY, int toX, int toY) const;
};

#endif

