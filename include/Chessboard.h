//
// *****************************************************
// *                                                   *
// * O Lord, Thank you for your goodness in our lives. *
// *     Please bless this code to our compilers.      *
// *                     Amen.                         *
// *                                                   *
// *****************************************************
//

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

struct position{
    int row;
    int col;
};

using std::vector;
using std::string;

const int BOARD_SIZE  = 8;

const string defaultFen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR"; 

#include "Bishop.h"
#include "Pawn.h"
#include "Knight.h"
#include "Queen.h"
#include "King.h"
#include "Rook.h"
#include "Piece.h"
#include "Chess_constants.h"

class Chessboard{
private:
    vector<vector<Piece>> board;

public:

// Monta o tabuleiro a partir de um dado defaultFen
// vide: https://www.chess.com/terms/fen-chess
    Chessboard();

//Imprime o tabuleiro na saida padrao
    void printBoard()const;

// retorna Piece
    Piece retPiece(const int row, const int col) const;

// move a piece a partir de um clique na tela
    void movepiece(const position from, const position to );

// verifica se o movimento é valido
    bool isValidMove(const position from, const position to )const;
// verifica se o caminho esta limpo
    bool isPathClear(const position from, const position to )const;
};

#endif 