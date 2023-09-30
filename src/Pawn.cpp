#include "../include/Pawn.h"

Pawn::Pawn(int pawncolor): Piece(PAWN, pawncolor){}

bool Pawn::isValidMove(int fromX, int fromY, int toX, int toY) const{
    bool verify = fromX || fromY || toX || toY;
    return verify;
}

void Pawn::promote(){}
