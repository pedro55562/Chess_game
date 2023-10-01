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

#include "Chess_constants.h"
#include "Piece.h"

class Bishop : public Piece{

public:
    Bishop(int BishopColor);
    
    bool isValidMove(int fromX, int fromY, int toX, int toY) const;

};

#endif 