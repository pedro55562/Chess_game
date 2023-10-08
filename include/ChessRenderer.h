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

const Color dark = {161,111,90,255};
const Color light = {235,210,184,255};
const Color red_ = {230, 41, 55, 60};

class ChessRenderer {
public:
    ChessRenderer(Chessboard& chessboard);
    ~ChessRenderer();

    void render(); 
    void renderBoard(const int row, const int col)const;
    void renderPossibleDestinations(const position from)const;
    void renderPiece(const Texture2D pieceTexture,const int col, const int row)const; 
    bool shouldClose()const;
    position handleMouseInput(bool& shouldclse);
    void updateSelectedPiece( const position from);


private:
    Chessboard& board; 
    position SelectedPiece;
    bool isPieceSelected;

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