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

Pawn::Pawn(int pawncolor): Piece(PAWN, pawncolor){
}

bool Pawn::isValidPawnMove(position from, position to, int numofmoves, int toCollor) {
    bool verify = false;


    if ( numofmoves > 0 && toCollor == EMPTY) {
        if (getColor() == WHITEn) {
            if (to.col == from.col && to.row == from.row - 1) {
                verify = true;
            }
        }
        if (getColor() == BLACKn && toCollor == EMPTY) {
            if (to.col == from.col && to.row == from.row + 1) {
                verify = true;
            }
        }
    }

    if (numofmoves == 0 && toCollor == EMPTY) {
        if (getColor() == WHITEn) {
            if (to.col == from.col && to.row == from.row - 1) {
                verify = true;
            }   
            if (to.col == from.col && to.row == from.row - 2) {
                verify = true;
            }
        }
        if (getColor() == BLACKn) {
            if (to.col == from.col && to.row == from.row + 1) {
                verify = true;
            }
            if (to.col == from.col && to.row == from.row + 2) {
                verify = true;
            }
        }
    }
    if (verify == false && toCollor != EMPTY){

        if (getColor() == BLACKn && toCollor == WHITEn){
            if (((to.col == from.col + 1) || (to.col == from.col - 1)) && (to.row == from.row + 1))
            {
                verify = true;
            }
        }
        if (getColor() == WHITEn && toCollor == BLACKn){
            if ( ((to.col == from.col + 1) || (to.col == from.col - 1)) && (to.row == from.row - 1))
            {
                verify = true;
            }
        }
    }
    

    return verify;
}

void Pawn::promote() {}

