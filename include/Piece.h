//
// *****************************************************
// *                                                   *
// * O Lord, Thank you for your goodness in our lives. *
// *     Please bless this code to our compilers.      *
// *                     Amen.                         *
// *                                                   *
// *****************************************************
//

#ifndef PIECE_H
#define PIECE_H 

#include "Chess_constants.h"

class Piece{
    private:
        int type;
        int color;  
        int numofmoves;
    public:

        Piece(int type1, int color1);

        Piece();
        
        // retorna o tipo de piece
        int getType() const;

        // retorna a cor de piece
        int getColor() const;

        int numof()const;

        void adnumof();
};

#endif 