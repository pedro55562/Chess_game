#include "../include/Bishop.h"

Bishop::Bishop(int BishopColor) : Piece(BISHOP, BishopColor) {}

bool Bishop::isValidMove(int fromX, int fromY, int toX, int toY) const{
    bool verify = fromX || fromY || toX || toY;
    return verify;
}