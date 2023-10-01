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
  position temp ;
  Chessboard board;
  board.printBoard();
  ChessRenderer graphicboard(board);
  while ( graphicboard.shouldClose() != true){
    graphicboard.render();
    temp = graphicboard.handleMouseInput();
    if ( temp.row != -1 && temp.col != -1){
      cout << endl << temp.row << "   " << temp.col << endl;
    }
  }
}
