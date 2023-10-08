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
#include <list>
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::list;
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
    if (retPiece(from.row, from.col).getType() != EMPTY && retPiece(to.row, to.col).getType() == EMPTY && isValidMove(from, to))
    {
        board[from.row][from.col].adnumof();
        board[to.row][to.col] = board[from.row][from.col];
        board[from.row][from.col] = Piece(EMPTY, EMPTY);
    }
    if (retPiece(from.row, from.col).getType() != EMPTY && retPiece(to.row, to.col).getType() != EMPTY && isValidMove(from, to))
    {
        board[from.row][from.col].adnumof();
        board[to.row][to.col] = Piece(EMPTY, EMPTY);
        board[to.row][to.col] = board[from.row][from.col];
        board[from.row][from.col] = Piece(EMPTY, EMPTY);
    }
}

bool Chessboard::isValidMove(const position from, const position to) const
{   
    bool isitclear = isPathClear(from, to);
    bool verify = false;
    switch (retPiece(from.row, from.col).getType())
    {
    case KING:
    {
        King k(retPiece(from.row, from.col).getColor());
        verify = k.isValidKingMove(from.col, from.row, to.col, to.row);
        return verify && isitclear;
        break;
    }
    case PAWN:
    {
        Pawn p(retPiece(from.row, from.col).getColor());
        verify = p.isValidPawnMove(from, to, board[from.row][from.col].numof(), board[to.row][to.col].getColor());
        return verify && isitclear;
        break;
    }
    case BISHOP:
    {
        Bishop b(retPiece(from.row, from.col).getColor());
        verify = b.isValidBishopMove(from.col, from.row, to.col, to.row);
        return verify && isitclear;
        break;
    }
    case QUEEN:
    {
        Queen q(retPiece(from.row, from.col).getColor());
        verify = q.isValidQueenMove(from.col, from.row, to.col, to.row);
        return verify && isitclear;
        break;
    }
    case KNIGHT:
    {
        Knight n(retPiece(from.row, from.col).getColor());
        verify = n.isValidKnightMove(from.col, from.row, to.col, to.row);
        return verify;
        break;
    }
    case ROOK:
    {
        Rook r(retPiece(from.row, from.col).getColor());
        verify = r.isValidRookMove(from.col, from.row, to.col, to.row);
        return verify && isitclear;
        break;
    }
    }
    return false;
}

bool Chessboard::isPathClear(const position from, const position to) const
{   
    if (from.row == to.row && from.col == to.col){
        return false;
    }
    int dRow = to.row - from.row;
    int dCol = to.col - from.col;

    // movimento diagonal:
    if (abs(dRow) == abs(dCol))
    {
        int dirRow = (dRow > 0) ? 1 : -1;
        int dirCol = (dCol > 0) ? 1 : -1;
        for (int curRow = from.row + dirRow, curCol = from.col + dirCol; curRow != to.row && curCol != to.col; curRow += dirRow, curCol += dirCol)
        {
            if ( curRow > -1 && curRow < 8 && curCol > -1 && curCol < 8 ){
                if (retPiece(curRow, curCol).getType() != EMPTY)
                {
                    return false;
                }
            }
        }
    }
    // movimento pelas rows
    if (dCol == 0 && dRow != 0)
    {
        int dirRow = (dRow > 0) ? 1 : -1;
        for (int curRow = from.row + dirRow; curRow != to.row; curRow += dirRow)
        {
            if ( curRow > -1 && curRow < 8){
                if (retPiece(curRow, from.col).getType() != EMPTY)
                {
                    return false;
                }
            }
        }
    }
    // movimento pelas cols
    if (dCol != 0 && dRow == 0)
    {
        int dirCol = (dCol > 0) ? 1 : -1;
        for (int curCol = from.col + dirCol; curCol != to.col;curCol += dirCol)
        {
            if (curCol > -1 && curCol < 8 ){
                if (retPiece(from.row, curCol).getType() != EMPTY)
                {
                    return false;
                }
            }
        }
    }
    return true;
}


list<position> Chessboard::getPossibleDestinations(const position from)
{
    list<position> lista_;
    vector<int> dirRow = {1, -1};
    vector<int> dirCol = {1, -1};
    switch (retPiece(from.row, from.col).getType())
    {

    case KING:
    {
        vector<int> kdirRow = {0,1, -1};
        vector<int> kdirCol = {0,1, -1};
        for (int dr : kdirRow)
        {
            for (int dc : kdirCol)
            {
                position dest = {from.row + dr , from.col + dc };
                if ( dest.row < 8 && dest.row > -1 && dest.col < 8 && dest.col > -1 ){
                    if (isValidMove(from, dest) && retPiece(dest.row, dest.col).getColor() != retPiece(from.row, from.col).getColor())
                    {
                        lista_.push_back(dest);
                    }
                }
            }
        }
        break;
    }

    case PAWN:
    {
        vector<int> PdirRow = {-1,-2,1, 2};
        vector<int> PdirCol = {0,1, -1};
        for (int dr : PdirRow)
        {
            for (int dc : PdirCol)
            {
                position dest = {from.row + dr , from.col + dc };
                if ( dest.row < 8 && dest.row > -1 && dest.col < 8 && dest.col > -1 ){
                    if (isValidMove(from, dest) && retPiece(dest.row, dest.col).getColor() != retPiece(from.row, from.col).getColor())
                    {
                        lista_.push_back(dest);
                    }
                }
            }
        }
        break;
    }

    case BISHOP:
    {
        // movimento diagonal
        for (int dr : dirRow)
        {
            for (int dc : dirCol)
            {
                for (int curRow = from.row + dr, curCol = from.col + dc; curRow < BOARD_SIZE && curRow > -1 && curCol < BOARD_SIZE && curCol > -1; curCol += dc, curRow += dr)
                {
                    position dest = {curRow, curCol};
                    if (isValidMove(from, dest) && retPiece(dest.row, dest.col).getColor() != retPiece(from.row, from.col).getColor())
                    {
                        lista_.push_back(dest);
                    }
                }
            }
        }

        break;
    }
    case QUEEN:
    {
        // movimento vertical ( pelas rows )
        for (int dr : dirRow)
        {
            for (int curRow = from.row + dr; curRow < BOARD_SIZE && curRow > -1; curRow += dr)
            {
                position dest = {curRow, from.col};
                if (isValidMove(from, dest) && retPiece(dest.row, dest.col).getColor() != retPiece(from.row, from.col).getColor())
                {
                    lista_.push_back(dest);
                }
            }
        }
        // movimento horizontal ( pelas cols)
        for (int dc : dirCol)
        {
            for (int curCol = from.col + dc; curCol < BOARD_SIZE && curCol > -1; curCol += dc)
            {
                position dest = {from.row, curCol};
                if (isValidMove(from, dest) && retPiece(dest.row, dest.col).getColor() != retPiece(from.row, from.col).getColor())
                {
                    lista_.push_back(dest);
                }
            }
        }

        // movimento diagonal
        for (int dr : dirRow)
        {
            for (int dc : dirCol)
            {
                for (int curRow = from.row + dr, curCol = from.col + dc; curRow < BOARD_SIZE && curRow > -1 && curCol < BOARD_SIZE && curCol > -1; curCol += dc, curRow += dr)
                {
                    position dest = {curRow, curCol};
                    if (isValidMove(from, dest) && retPiece(dest.row, dest.col).getColor() != retPiece(from.row, from.col).getColor())
                    {
                        lista_.push_back(dest);
                    }
                }
            }
        }


        break;
    }
    case KNIGHT:
    {
        vector<int> ndirRow = {-1 , 1 , 2 , -2};
        vector<int> ndirCol = {-1 , 1 , 2 , -2};
        for (int dr : ndirRow)
        {
            for (int dc : ndirCol)
            {
                for (int curRow = from.row + dr, curCol = from.col + dc; curRow < BOARD_SIZE && curRow > -1 && curCol < BOARD_SIZE && curCol > -1; curCol += dc, curRow += dr)
                {
                    position dest = {curRow, curCol};
                    if (isValidMove(from, dest) && retPiece(dest.row, dest.col).getColor() != retPiece(from.row, from.col).getColor())
                    {
                        lista_.push_back(dest);
                    }
                }
            }
        }

        break;
    }
    case ROOK:
    {
        // movimento vertical ( pelas rows )
        for (int dr : dirRow)
        {
            for (int curRow = from.row + dr; curRow < BOARD_SIZE && curRow > -1; curRow += dr)
            {
                position dest = {curRow, from.col};
                if (isValidMove(from, dest) && retPiece(dest.row, dest.col).getColor() != retPiece(from.row, from.col).getColor())
                {
                    lista_.push_back(dest);
                }
            }
        }
        // movimento horizontal ( pelas cols)
        for (int dc : dirCol)
        {
            for (int curCol = from.col + dc; curCol < BOARD_SIZE && curCol > -1; curCol += dc)
            {
                position dest = {from.row, curCol};
                if (isValidMove(from, dest) && retPiece(dest.row, dest.col).getColor() != retPiece(from.row, from.col).getColor())
                {
                    lista_.push_back(dest);
                }
            }
        }

        break;
    }
    }
    return lista_;
}
