#include "../include/King.h"

King::King(int KingColor): Piece(KING,KingColor){}

bool King::isValidMove(int fromX, int fromY, int toX, int toY) const
{
    bool verify = fromX || fromY || toX || toY;
    return verify;
}