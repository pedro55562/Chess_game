//
// *****************************************************
// *                                                   *
// * O Lord, Thank you for your goodness in our lives. *
// *     Please bless this code to our compilers.      *
// *                     Amen.                         *
// *                                                   *
// *****************************************************
//

#ifndef KING_H
#define KING_H

#include "Piece.h"
#include "Chess_constants.h"

#include <cmath>

class King : public Piece{
    public:
        
        King(int KingColor);
        bool isValidKingMove(int fromX, int fromY, int toX, int toY) const;
};

#endif