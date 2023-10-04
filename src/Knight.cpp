//
// *****************************************************
// *                                                   *
// * O Lord, Thank you for your goodness in our lives. *
// *     Please bless this code to our compilers.      *
// *                     Amen.                         *
// *                                                   *
// *****************************************************
//

#include "../include/Knight.h"

Knight::Knight(int KingColor) : Piece(KNIGHT,KingColor) {}

bool Knight::isValidKnightMove(int fromX, int fromY, int toX, int toY) const{
    bool ver = false;
    int dx = abs(fromX - toX);
    int dy = abs(fromY - toY);
    ver = ( ((dx == 1) && (dy==2)) || ((dx  == 2) && (dy==1)) );
    return ver ;
}
