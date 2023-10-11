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
  string fen = "n2q4/p2kP1p1/1b2r3/6p1/p2n2p1/r7/3P2Q1/5K2";
  Chessboard board(fen);
  ChessRenderer graphicboard(board);
  while ( !graphicboard.shouldClose() ){

    graphicboard.render();
    position movefrom = graphicboard.handleMouseInput();
    graphicboard.updateSelectedPiece(movefrom);
    position moveto;
    if (board.retPiece(movefrom.row, movefrom.col).getType() != EMPTY && graphicboard.shouldClose() == false){
      moveto = graphicboard.handleMouseInput();
    }
    board.movepiece(movefrom, moveto);
    graphicboard.updateSelectedPiece(movefrom);
  }
   
}