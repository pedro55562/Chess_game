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

#include "Bishop.h"
#include "Pawn.h"
#include "Knight.h"
#include "Queen.h"
#include "King.h"
#include "Rook.h"
#include "Piece.h"
#include "Chess_constants.h"

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using std::vector;
using std::string;

const int BOARD_SIZE  = 8;

const string defaultFen = "8/5k2/3p4/1p1Pp2p/pP2Pp1P/P4P1K/8/8"; 

struct position{
    int row;
    int col;
};

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
};

#endif 