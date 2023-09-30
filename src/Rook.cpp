#include "../include/Rook.h"

Rook::Rook(int RookColor) : Piece(ROOK, RookColor){}

bool Rook::isValidMove(int fromX, int fromY, int toX, int toY) const{
    bool verify = fromX || fromY || toX || toY;
    return verify;
}
