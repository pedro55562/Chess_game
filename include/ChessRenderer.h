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

// constantes do tabuleiro
const int size = 8;
const int pixels = 800;
const int squaresize = pixels/size;

// cores do tabuleiro em RGBA
// vide: https://en.wikipedia.org/wiki/RGBA_color_model
const Color dark = {161,111,90,255};
const Color light = {235,210,184,255};
const Color red_ = {230, 41, 55, 60};

class ChessRenderer {
public:
// Construtor: Inicia a janela e carrega texturas
    ChessRenderer(Chessboard& chessboard);

// Destrutor: Descarrega texturas e fecha janelas
    ~ChessRenderer();

// função responsavel pela renderização geral
    void render(); 

// função responsavel por renderizar o tabuleiro(o fundo)
    void renderBoard(const int row, const int col)const;

// função responsavel por renderizar as pieces
    void renderPiece(const Texture2D pieceTexture,const int col, const int row)const; 

// função responsavel por renderizar a marcação de destinos possiveis
    void renderPossibleDestinations(const position from)const;

// retorna se a janela deve ou nao fechar
    bool shouldClose()const;

// retorna a posição em um clique do mouse
// ja convertido de pixels para linhas e colunas
    position handleMouseInput(bool& shouldclse);

// atualiza qual piece esta selecionada
    void updateSelectedPiece( const position from);

private:

// referencia para o tabuleiro do backend
    Chessboard& board; 

// armazena qual piece esta selecionada
    position SelectedPiece;

// armazena se alguma piece esta selecionada
    bool isPieceSelected;

// Declaração das texturas das pieces serem carregegadas 
// a partir do diretorio " ./assets/images/chess_pieces "
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