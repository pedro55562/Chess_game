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

#include <raylib.h>

int main (){
  Chessboard board;
  ChessRenderer graphicboard(board);
  board.printBoard();
  while ( graphicboard.shouldClose() != true){
    graphicboard.render();
  }
  return 0;
}
