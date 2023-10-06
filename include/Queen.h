//
// *****************************************************
// *                                                   *
// * O Lord, Thank you for your goodness in our lives. *
// *     Please bless this code to our compilers.      *
// *                     Amen.                         *
// *                                                   *
// *****************************************************
//

#ifndef QUEEN_H
#define QUEEN_H

#include "Chess_constants.h"
#include "Piece.h"

#include <cmath>

class Queen : public Piece{
public:
    Queen(int QueenColor);
    bool isValidQueenMove(int fromX, int fromY, int toX, int toY) const;

};

#endif
