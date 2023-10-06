//
// *****************************************************
// *                                                   *
// * O Lord, Thank you for your goodness in our lives. *
// *     Please bless this code to our compilers.      *
// *                     Amen.                         *
// *                                                   *
// *****************************************************
//

#ifndef BISHOP_H
#define BISHOP_H

#include <cmath>

#include "Chess_constants.h"
#include "Piece.h"

class Bishop : public Piece{

public:
    Bishop(int BishopColor);
    
    bool isValidBishopMove(int fromX, int fromY, int toX, int toY) const;

};

#endif 