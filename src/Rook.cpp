//
// *****************************************************
// *                                                   *
// * O Lord, Thank you for your goodness in our lives. *
// *     Please bless this code to our compilers.      *
// *                     Amen.                         *
// *                                                   *
// *****************************************************
//

#include "../include/Rook.h"

Rook::Rook(int RookColor) : Piece(ROOK, RookColor){}

bool Rook::isValidRookMove(int fromX, int fromY, int toX, int toY) const{
    int dx = abs(fromX - toX);
    int dy = abs(fromY - toY);
    return (dx != 0 && dy == 0)||(dx == 0 && dy != 0);
}
