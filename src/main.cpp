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

int main (){
  Chessboard board;
  board.printBoard();
  ChessRenderer graphicboard(board);
  bool shouldclose = false;
  while ( !shouldclose ){
    if ( graphicboard.shouldClose() == true){
      shouldclose = true;
    }
    graphicboard.render();
    position movefrom = graphicboard.handleMouseInput(shouldclose);
    position moveto;
    if (board.retPiece(movefrom.row,movefrom.col).getType() != EMPTY){
      moveto = graphicboard.handleMouseInput(shouldclose);
    }    
    board.movepiece(movefrom, moveto);
  
  } 
}