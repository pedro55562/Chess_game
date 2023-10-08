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

#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "Chessboard.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

void imprimirTabuleiro(const vector<vector<char>> &tabuleiro)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            std::cout << tabuleiro[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<char>> lerFEN(const string &fen)
{
    vector<vector<char>> tabuleiro(BOARD_SIZE, vector<char>(BOARD_SIZE, ' '));
    int row = 0;
    int col = 0;
    for (char c : fen)
    {
        if (c == ' ')
        {
            break;
        }
        else if (c == '/')
        {
            row++;
            col = 0;
        }
        else if (isdigit(c))
        {
            int espacosVazios = c - '0';
            for (int i = 0; i < espacosVazios; i++)
            {
                tabuleiro[row][col] = '.';
                col++;
            }
        }
        else
        {
            // Preenche com a peça
            tabuleiro[row][col] = c;
            col++;
        }
    }

    return tabuleiro;
}

Chessboard::Chessboard()
{
    board.resize(8, vector<Piece>(8));
    vector<vector<char>> auxboard = lerFEN(defaultFen);
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            switch (auxboard[i][j])
            {
            case '.':
                board[i][j] = Piece(EMPTY, EMPTY);
                break;
            case 'p':
                board[i][j] = Pawn(BLACKn);
                break;
            case 'P':
                board[i][j] = Pawn(WHITEn);
                break;
            case 'r':
                board[i][j] = Piece(ROOK, BLACKn);
                break;
            case 'R':
                board[i][j] = Piece(ROOK, WHITEn);
                break;
            case 'n':
                board[i][j] = Piece(KNIGHT, BLACKn);
                break;
            case 'N':
                board[i][j] = Piece(KNIGHT, WHITEn);
                break;
            case 'b':
                board[i][j] = Piece(BISHOP, BLACKn);
                break;
            case 'B':
                board[i][j] = Piece(BISHOP, WHITEn);
                break;
            case 'q':
                board[i][j] = Piece(QUEEN, BLACKn);
                break;
            case 'Q':
                board[i][j] = Piece(QUEEN, WHITEn);
                break;
            case 'k':
                board[i][j] = Piece(KING, BLACKn);
                break;
            case 'K':
                board[i][j] = Piece(KING, WHITEn);
                break;
            }
        }
    }
}

void Chessboard::printBoard() const
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << board[i][j].getType() << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << board[i][j].getColor() << " ";
        }
        cout << endl;
    }
    cout << endl;
        for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << board[i][j].numof() << " ";
        }
        cout << endl;
    }
    cout << "--------";
    cout << endl;
}

Piece Chessboard::retPiece(const int row, const int col) const
{
    return board[row][col];
}

void Chessboard::movepiece(const position from, const position to)
{
    if (retPiece(from.row, from.col).getType() == EMPTY)
    {
        return;
    }
    if (retPiece(from.row, from.col).getColor() == retPiece(to.row, to.col).getColor())
    {
        return;
    }
    if (retPiece(from.row, from.col).getType() != EMPTY && retPiece(to.row, to.col).getType() == EMPTY && isValidMove(from,to) )
    {
        board[from.row][from.col].adnumof(); 
        board[to.row][to.col] = board[from.row][from.col];
        board[from.row][from.col] = Piece(EMPTY, EMPTY);
    }
    if (retPiece(from.row, from.col).getType() != EMPTY && retPiece(to.row, to.col).getType() != EMPTY && isValidMove(from,to) )
    {
        board[from.row][from.col].adnumof(); 
        board[to.row][to.col] = Piece(EMPTY, EMPTY);
        board[to.row][to.col] = board[from.row][from.col];
        board[from.row][from.col] = Piece(EMPTY, EMPTY);
    }
}

bool Chessboard::isValidMove(const position from, const position to) const
{
    bool isitclear = isPathClear(from,to);
    bool verify = false;
    switch ( retPiece(from.row, from.col).getType() )
    {
    case KING :{
        King k( retPiece(from.row, from.col).getColor() );
        verify = k.isValidKingMove(from.col, from.row, to.col,to.row);
        return verify && isitclear;
        break;
    }
    case PAWN:{
        Pawn p( retPiece(from.row, from.col).getColor() );
        verify = p.isValidPawnMove( from,to, board[from.row][from.col].numof() , board[to.row][to.col].getColor() );
        return verify && isitclear;
        break;
    }
    case BISHOP:{
        Bishop b( retPiece(from.row, from.col).getColor() );
        verify = b.isValidBishopMove(from.col, from.row, to.col,to.row);
        return verify && isitclear;
        break;
    }
    case QUEEN:{
        Queen q( retPiece(from.row, from.col).getColor() );
        verify = q.isValidQueenMove(from.col, from.row, to.col,to.row);
        return verify && isitclear;
        break;
    }
    case KNIGHT:{
        Knight n( retPiece(from.row, from.col).getColor() );
        verify = n.isValidKnightMove(from.col, from.row, to.col,to.row);
        return verify;
        break;
    }
    case ROOK:{
        Rook r( retPiece(from.row, from.col).getColor() );
        verify = r.isValidRookMove(from.col, from.row, to.col,to.row);
        return verify && isitclear;
        break;
    }
    }
}

bool Chessboard::isPathClear(const position from, const position to) const
{
    cout << endl <<" FROM: " << from.row << " " << from.col << endl;
    cout << endl <<" TO: " << to.row << " " << to.col << endl << endl;


    int dRow = to.row - from.row;
    int dCol = to.col - from.col;

    // movimento diagonal:
    if (abs(dRow) == abs(dCol)){
        int dirRow = (dRow > 0)? 1 : -1;
        int dirCol = (dCol > 0)? 1 : -1;
        for (int curRow = from.row + dirRow, curCol = from.col + dirCol; curRow != to.row && curCol != to.col ; ){
            if ( retPiece(curRow, curCol).getType() != EMPTY){
                return false;
            }
            curRow+=dirRow;
            curCol+=dirCol;
        }
    }
    // movimento pelas rows
    if (dCol == 0 && dRow != 0){
        int dirRow = (dRow > 0)? 1 : -1;
        for (int curRow = from.row + dirRow; curRow != to.row; ){
            if ( retPiece(curRow, from.col).getType() != EMPTY){
                return false;
            }
            curRow+=dirRow;
        }
    }
    // movimento pelas cols
    if (dCol != 0 && dRow == 0){
        int dirCol = (dCol > 0)? 1 : -1;
        for (int curCol = from.row + dirCol; curCol != to.row; ){
            if ( retPiece(curCol, from.col).getType() != EMPTY){
                return false;
            }
            curCol+=dirCol;
        }
    }
    return true;
}