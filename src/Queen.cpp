#include "../include/Queen.h"

Queen::Queen(int QueenColor) : Piece(QUEEN, QueenColor) {}


bool Queen::isValidMove(int fromX, int fromY, int toX, int toY) const{
    bool verify = fromX || fromY || toX || toY;
    return verify;
}
