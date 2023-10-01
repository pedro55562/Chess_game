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
}

Piece::Piece(){
    type = EMPTY;
    color = EMPTY;
}
int Piece::getType() const
{
    return type;
}

int Piece::getColor()const{
    return color;
}
