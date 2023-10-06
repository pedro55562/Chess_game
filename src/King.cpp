//
// *****************************************************
// *                                                   *
// * O Lord, Thank you for your goodness in our lives. *
// *     Please bless this code to our compilers.      *
// *                     Amen.                         *
// *                                                   *
// *****************************************************
//

#include "../include/King.h"

King::King(int KingColor): Piece(KING,KingColor){}

bool King::isValidKingMove(int fromX, int fromY, int toX, int toY) const
{
    int dx = abs(fromX - toX);
    int dy = abs(fromY - toY);
    return (dx == 1 && dy == 0)||(dx == 0 && dy == 1)||( dx == 1 && dy == 1);
}