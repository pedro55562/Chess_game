//
// *****************************************************
// *                                                   *
// * O Lord, Thank you for your goodness in our lives. *
// *     Please bless this code to our compilers.      *
// *                     Amen.                         *
// *                                                   *
// *****************************************************
//

#ifndef PAWN_H
#define PAWN_H

#include "Chessboard.h"
#include "Chess_constants.h"
#include "Piece.h"

class Pawn : public Piece {
public:
    Pawn(int pawncolor);

    bool isValidMove(position from, position to);
    void promote(); 
};

#endif 