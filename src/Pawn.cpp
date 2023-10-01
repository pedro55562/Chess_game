//
// *****************************************************
// *                                                   *
// * O Lord, Thank you for your goodness in our lives. *
// *     Please bless this code to our compilers.      *
// *                     Amen.                         *
// *                                                   *
// *****************************************************
//

#include "../include/Pawn.h"

Pawn::Pawn(int pawncolor): Piece(PAWN, pawncolor){}

bool Pawn::isValidMove(position from, position to){
    bool verify = false;
    if (getColor() == WHITEn){
        if (to.col == from.col && to.col == from.col + 1){
            verify = true;
        }
    }
    
    return verify;
}

void Pawn::promote(){}
