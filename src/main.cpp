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

#include <list>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <raylib.h>

using std::vector;
using std::list;
using std::string;
using std::cout;
using std::endl;

int main (){
  Chessboard board;
  ChessRenderer graphicboard(board);
  bool shouldclose = false;
  while ( !shouldclose ){
    if ( graphicboard.shouldClose() == true){
      shouldclose = true;
    }
    graphicboard.render();
    position movefrom = graphicboard.handleMouseInput(shouldclose);
    graphicboard.updateSelectedPiece(movefrom);
    position moveto;
    if (board.retPiece(movefrom.row, movefrom.col).getType() != EMPTY && shouldclose == false){
      moveto = graphicboard.handleMouseInput(shouldclose);
    }
    board.movepiece(movefrom, moveto);
    graphicboard.updateSelectedPiece(movefrom);
  }
   
}