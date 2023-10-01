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

const string defaultFen = "r1bk3r/p2pBpNp/n4n2/1p1NP2P/6P1/3P4/P1P1K3/q5b1"; 

class Chessboard
{
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
    
};

#endif 