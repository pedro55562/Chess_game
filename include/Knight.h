//
// *****************************************************
// *                                                   *
// * O Lord, Thank you for your goodness in our lives. *
// *     Please bless this code to our compilers.      *
// *                     Amen.                         *
// *                                                   *
// *****************************************************
//

#ifndef KNIGHT_H
#define KNIGHT_H

#include <cmath>

#include "Piece.h"
#include "Chess_constants.h"

class Knight : public Piece{
    public:
        
        Knight(int KingColor);
        bool isValidKnightMove(int fromX, int fromY, int toX, int toY) const;
};

#endif

