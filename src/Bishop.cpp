//
// *****************************************************
// *                                                   *
// * O Lord, Thank you for your goodness in our lives. *
// *     Please bless this code to our compilers.      *
// *                     Amen.                         *
// *                                                   *
// *****************************************************
//

#include "../include/Bishop.h"

Bishop::Bishop(int BishopColor) : Piece(BISHOP, BishopColor) {}

bool Bishop::isValidBishopMove(int fromX, int fromY, int toX, int toY) const{
    int dx = abs(fromX - toX);
    int dy = abs(fromY - toY);
    return dx == dy;
}