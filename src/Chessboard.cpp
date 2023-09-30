#include "../include/Chessboard.h"
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;

const string defaultFen = "rnb2qnr/pp1p4/6p1/2p1k1B1/2K1p3/3P4/PPP2PPP/RN3B1R"; 


Chessboard::Chessboard(){
    board.resize(8, vector<Piece>(8));
    int row = 7;
    int col = 0;
    char numEmpty = '?';
    Piece aux1(EMPTY, EMPTY);
    for ( int l =  (int) defaultFen.size() - 1; l >=0  ; l--){
        if (row < 0){
         break;
        }
        switch (defaultFen[l]){
            case 'r':
                aux1 = Rook(BLACKn);
                break;
            case 'R':
                aux1 = Rook(WHITEn);
                break;        
            case 'b':
                aux1 = Bishop(BLACKn);
                break; 
            case 'B':
                aux1 = Bishop(WHITEn);
                break; 
            case 'n':
                aux1 = Knight(BLACKn);
                break; 
            case 'N':
                aux1 = Knight(WHITEn);
                break; 
            case 'q':
                aux1 = Queen(BLACKn);
                break; 
            case 'Q':
                aux1 = Queen(WHITEn);
                break;  
            case 'k':
                aux1 = King(BLACKn);
                break; 
            case 'K':
                aux1 = King(WHITEn);
                break; 
            case 'p':
                aux1 = Pawn(BLACKn);
                break; 
            case 'P':
                aux1 = Pawn(WHITEn);
                break; 
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
                numEmpty = defaultFen[l];
                break;
            case '/':
                row--;
                break;
            default:
                break;
        }
        if (numEmpty != '?'){
            int num = (int) numEmpty - '0';
            aux1 = Piece(EMPTY,EMPTY);
            for (int i = 0; i < num; i++){
                board[row][col] = aux1;
                col++;
            }
            numEmpty = '?';
        }
        if (aux1.getType() != EMPTY && aux1.getColor() != EMPTY ){
            board[row][col] = aux1;
            col++;
            aux1 = Piece(EMPTY,EMPTY);
            numEmpty = '?';
        }
        if (col > 7){
            col = 0;
        }
    }
}

void Chessboard::printBoard()const{
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
