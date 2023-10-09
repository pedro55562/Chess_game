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

Pawn::Pawn(int pawncolor) : Piece(PAWN, pawncolor)
{
}

bool Pawn::isValidPawnMove(position from, position to, int toCollor)
{
    int drow = to.row - from.row;
    int dcol = to.col - from.col;

    if (dcol == 0 && toCollor == EMPTY)
    {
        if (getColor() == BLACKn)
        {
            if (from.row == 1)
            {
                return (drow == 1) || (drow == 2);
            }
            if (from.row != 1)
            {
                return (drow == 1);
            }
        }
        if (getColor() == WHITEn)
        {
            if (from.row == 6)
            {
                return (drow == -1) || (drow == -2);
            }
            if (from.row != 1)
            {
                return (drow == -1);
            }
        }
    }

    if ((toCollor != EMPTY) && (dcol == 1 || dcol == -1) )
    {

        if (getColor() == BLACKn && toCollor == WHITEn)
        {
            return ((dcol == 1)||(dcol == -1))&&(drow == 1);
        }
        if (getColor() == WHITEn && toCollor == BLACKn)
        {
            return ((dcol == 1)||(dcol == -1))&&(drow == -1);
        }
    }

    return false;
}
