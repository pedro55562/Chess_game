//
// *****************************************************
// *                                                   *
// * O Lord, Thank you for your goodness in our lives. *
// *     Please bless this code to our compilers.      *
// *                     Amen.                         *
// *                                                   *
// *****************************************************
//

#ifndef CHESSRENDER_H
#define CHESSRENDER_H

#include "Chessboard.h"
#include "Bishop.h"
#include "Pawn.h"
#include "Knight.h"
#include "Queen.h"
#include "King.h"
#include "Rook.h"
#include "Piece.h"
#include "Chess_constants.h"

#include <raylib.h>

const int size = 8;
const int pixels = 800;
const int squaresize = pixels/size;

const Color dark = {210, 140, 69, 255};
const Color light = {255, 207, 159, 255};
const Color noInt = {0, 0, 0, 100};

class ChessRenderer {
public:
    ChessRenderer(Chessboard& chessboard);
    ~ChessRenderer();

    void render(); 
    void renderBoard(const int row, const int col)const;
    void renderPiece(const Texture2D pieceTexture,const int col, const int row)const; 
    bool shouldClose()const;
    position handleMouseInput(bool& shouldclse);


private:
    Chessboard& board; 

// TEXTURE
Texture2D BISHOP_BLACK;
Texture2D KING_BLACK;
Texture2D QUEEN_BLACK;
Texture2D ROOK_BLACK;
Texture2D KNIGHT_BLACK;
Texture2D PAWN_BLACK;

Texture2D BISHOP_WHITE;
Texture2D KING_WHITE;
Texture2D QUEEN_WHITE;
Texture2D ROOK_WHITE;
Texture2D KNIGHT_WHITE;
Texture2D PAWN_WHITE;
};

#endif