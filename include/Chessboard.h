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

using std::vector;
using std::string;

const int BOARD_SIZE  = 8;

const string defaultFen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR"; 

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