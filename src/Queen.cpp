//
// *****************************************************
// *                                                   *
// * O Lord, Thank you for your goodness in our lives. *
// *     Please bless this code to our compilers.      *
// *                     Amen.                         *
// *                                                   *
// *****************************************************
//

#include "../include/Queen.h"

Queen::Queen(int QueenColor) : Piece(QUEEN, QueenColor) {}


bool Queen::isValidQueenMove(int fromX, int fromY, int toX, int toY) const{
    int dx = abs(fromX - toX);
    int dy = abs(fromY - toY);
    return (dx == dy)||(dx != 0 && dy == 0)||(dx == 0 && dy != 0);
}
