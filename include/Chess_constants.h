#ifndef CHESS_CONSTANTS_H
#define CHESS_CONSTANTS_H

// Algumas constantes utilizadas:

/*
    Utilizaremos os 5 bits menos significativos de numeros inteiros para 
    representar cada peça, sendo os da 3 da direita sendo responsavel para o tipo
    e os 2 da esquerda para a cor.
    sendo:
    01: branco
    10: preto

    abaixo segue a declaração utilizando base 10:
*/

    // Constantes para representar casa vazia
    static const int EMPTY = 0;

    // Constantes para representar os tipos de peças
    static const int KING = 1;
    static const int QUEEN = 2;
    static const int ROOK = 3;
    static const int BISHOP = 4;
    static const int KNIGHT = 5;
    static const int PAWN = 6;

    // Constantes para representar as cores
    static const int WHITEn = 8;
    static const int BLACKn = 16;

#endif 