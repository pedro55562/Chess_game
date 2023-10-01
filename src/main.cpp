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
  while ( graphicboard.shouldClose() != true){
    graphicboard.render();
  }
  return 0;
}
