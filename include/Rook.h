//
// *****************************************************
// *                                                   *
// * O Lord, Thank you for your goodness in our lives. *
// *     Please bless this code to our compilers.      *
// *                     Amen.                         *
// *                                                   *
// *****************************************************
//

#ifndef ROOK_H
#define ROOK_H

#include "Chess_constants.h"
#include "Piece.h"

#include <cmath>

class Rook : public Piece{
public:
    Rook(int RookColor);
    bool isValidRookMove(int fromX, int fromY, int toX, int toY) const;    

};

#endif