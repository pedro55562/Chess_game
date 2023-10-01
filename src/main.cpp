//
// *****************************************************
// *                                                   *
// * O Lord, Thank you for your goodness in our lives. *
// *     Please bless this code to our compilers.      *
// *                     Amen.                         *
// *                                                   *
// *****************************************************
//

#include "../include/ChessRenderer.h"
#include "../include/Chessboard.h"
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
#include <raylib.h>

using std::vector;
using std::string;
using std::cout;
using std::endl;

vector<vector<char>> lerFEN(const string& fen);

void imprimirTabuleiro(const vector<vector<char>>& tabuleiro) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            std::cout << tabuleiro[i][j] << " ";
        }
        cout << endl;
    }
}

int main (){
  string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
  vector<vector<char>> tabuleiro = lerFEN(fen);
  imprimirTabuleiro(tabuleiro);
  
  Chessboard board;
  ChessRenderer graphicboard(board);
  board.printBoard();
  while ( graphicboard.shouldClose() != true){
    graphicboard.render();
  }
  return 0;
}
