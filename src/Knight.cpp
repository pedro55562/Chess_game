#include "../include/Knight.h"

Knight::Knight(int KingColor) : Piece(KNIGHT,KingColor) {}

bool Knight::isValidMove(int fromX, int fromY, int toX, int toY) const{
    bool verify = fromX || fromY || toX || toY;
    return verify;
}
