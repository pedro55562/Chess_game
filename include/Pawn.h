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
    bool isValidPawnMove(position from, position to, int numofmoves, int toCollor);
    void promote(); 
};

#endif 