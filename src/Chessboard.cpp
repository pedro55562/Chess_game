//
// *****************************************************
// *                                                   *
// * O Lord, Thank you for your goodness in our lives. *
// *     Please bless this code to our compilers.      *
// *                     Amen.                         *
// *                                                   *
// *****************************************************
//

#include "../include/Chessboard.h"

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "Chessboard.h"

using std::vector;
using std::string;
using std::cout;
using std::endl;

void imprimirTabuleiro(const vector<vector<char>>& tabuleiro) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            std::cout << tabuleiro[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<char>> lerFEN(const string& fen) {
    vector<vector<char>> tabuleiro(BOARD_SIZE, vector<char>(BOARD_SIZE, ' '));
    int row = 0;
    int col = 0;
    for (char c : fen) {
        if (c == ' ') {
            break; 
        } else if (c == '/') {
            row++;
            col = 0;
        } else if (isdigit(c)) {
            int espacosVazios = c - '0';
            for (int i = 0; i < espacosVazios; i++) {
                tabuleiro[row][col] = '.';
                col++;
            }
        } else {
            // Preenche com a peça
            tabuleiro[row][col] = c;
            col++;
        }
    }

    return tabuleiro;
}


Chessboard::Chessboard(){
    board.resize(8, vector<Piece>(8));
    vector<vector<char>> auxboard = lerFEN(defaultFen);
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (auxboard[i][j])
            {
            case '.': board[i][j] = Piece(EMPTY,EMPTY); break;
            case 'p': board[i][j] = Piece(PAWN,BLACKn); break;
            case 'P': board[i][j] = Piece(PAWN,WHITEn); break;
            case 'r': board[i][j] = Piece(ROOK,BLACKn); break;
            case 'R': board[i][j] = Piece(ROOK,WHITEn); break;
            case 'n': board[i][j] = Piece(KNIGHT,BLACKn); break;
            case 'N': board[i][j] = Piece(KNIGHT,WHITEn); break;
            case 'b': board[i][j] = Piece(BISHOP,BLACKn); break;
            case 'B': board[i][j] = Piece(BISHOP,WHITEn); break;
            case 'q': board[i][j] = Piece(QUEEN,BLACKn); break;
            case 'Q': board[i][j] = Piece(QUEEN,WHITEn); break;
            case 'k': board[i][j] = Piece(KING,BLACKn); break;
            case 'K': board[i][j] = Piece(KING,WHITEn); break;
            }
        }
    }
}

void Chessboard::   printBoard()const{
    for (int i = 0; i < 8 ; i++){
        for (int j = 0; j < 8 ; j++){
            cout << board[i][j].getType() << " " ;
        }
    cout << endl;
    }
    cout << endl;
        for (int i = 0; i < 8 ; i++){
            for (int j = 0; j < 8 ; j++){
            cout << board[i][j].getColor() << " " ;
        }
    cout << endl;
    }
    cout << endl;
}
Piece Chessboard::retPiece(const int row, const int col) const{
    return (Piece) board[row][col];
}
void Chessboard::movepiece(const position from, const position to){
    if ( retPiece(from.row , from.col).getType() == EMPTY ){
        return;
    }
    if ( retPiece(from.row , from.col).getColor() == retPiece(to.row , to.col).getColor() ){
        return;
    }
    if ( retPiece(from.row , from.col).getType() != EMPTY && retPiece(to.row , to.col).getType() == EMPTY){
        board[to.row][to.col] = board[from.row][from.col];
        board[from.row][from.col] = Piece(EMPTY,EMPTY);
    }
    if ( retPiece(from.row , from.col).getType() != EMPTY && retPiece(to.row , to.col).getType() != EMPTY ){
        board[to.row][to.col] = Piece(EMPTY,EMPTY);
        board[to.row][to.col] = board[from.row][from.col];
        board[from.row][from.col] = Piece(EMPTY,EMPTY);
    }    
}