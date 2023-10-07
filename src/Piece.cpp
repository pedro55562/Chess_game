//
// *****************************************************
// *                                                   *
// * O Lord, Thank you for your goodness in our lives. *
// *     Please bless this code to our compilers.      *
// *                     Amen.                         *
// *                                                   *
// *****************************************************
//

#include "../include/Piece.h"

Piece::Piece(int type1, int color1){
    type = type1;
    color = color1;
    numofmoves = 0;
}

Piece::Piece(){
    type = EMPTY;
    color = EMPTY;
    numofmoves = 0;
}

int Piece::getType() const
{
    return type;
}

int Piece::getColor() const{
    return color;
}

int Piece::numof() const{
    return numofmoves;
}

void Piece::adnumof(){
    numofmoves++;
}
