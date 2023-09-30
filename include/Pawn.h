#ifndef PAWN_H
#define PAWN_H


#include "Chess_constants.h"
#include "Piece.h"

class Pawn : public Piece {
public:
    Pawn(int pawncolor);

    bool isValidMove(int fromX, int fromY, int toX, int toY) const;
    void promote(); 
};

#endif 