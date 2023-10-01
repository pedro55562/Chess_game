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

#include <raylib.h>
#include <iostream>
using std::cout;
using std::endl;

ChessRenderer::ChessRenderer(Chessboard &chboard) : board(chboard)
{
  InitWindow(pixels, pixels, "Chess");

  SetTargetFPS(60);  
  // LOAD TEXTURES
  BISHOP_BLACK = LoadTextureFromImage(LoadImage("./assets/images/chess_pieces/BISHOP_BLACK.png"));
  KING_BLACK = LoadTextureFromImage(LoadImage("./assets/images/chess_pieces/KING_BLACK.png"));
  QUEEN_BLACK = LoadTextureFromImage(LoadImage("./assets/images/chess_pieces/QUEEN_BLACK.png"));
  ROOK_BLACK = LoadTextureFromImage(LoadImage("./assets/images/chess_pieces/ROOK_BLACK.png"));
  KNIGHT_BLACK = LoadTextureFromImage(LoadImage("./assets/images/chess_pieces/KNIGHT_BLACK.png"));
  PAWN_BLACK = LoadTextureFromImage(LoadImage("./assets/images/chess_pieces/PAWN_BLACK.png"));

  BISHOP_WHITE = LoadTextureFromImage(LoadImage("./assets/images/chess_pieces/BISHOP_WHITE.png"));
  KING_WHITE = LoadTextureFromImage(LoadImage("./assets/images/chess_pieces/KING_WHITE.png"));
  QUEEN_WHITE = LoadTextureFromImage(LoadImage("./assets/images/chess_pieces/QUEEN_WHITE.png"));
  ROOK_WHITE = LoadTextureFromImage(LoadImage("./assets/images/chess_pieces/ROOK_WHITE.png"));
  KNIGHT_WHITE = LoadTextureFromImage(LoadImage("./assets/images/chess_pieces/KNIGHT_WHITE.png"));
  PAWN_WHITE = LoadTextureFromImage(LoadImage("./assets/images/chess_pieces/PAWN_WHITE.png"));
}

ChessRenderer::~ChessRenderer()
{
  UnloadTexture(BISHOP_BLACK);
  UnloadTexture(KING_BLACK);
  UnloadTexture(QUEEN_BLACK);
  UnloadTexture(ROOK_BLACK);
  UnloadTexture(KNIGHT_BLACK);
  UnloadTexture(PAWN_BLACK);

  UnloadTexture(BISHOP_WHITE);
  UnloadTexture(KING_WHITE);
  UnloadTexture(QUEEN_WHITE);
  UnloadTexture(ROOK_WHITE);
  UnloadTexture(KNIGHT_WHITE);
  UnloadTexture(PAWN_WHITE);
  CloseWindow();
}

void ChessRenderer::render()
{
  BeginDrawing();
  for (int row = 0; row < size; row++)
  {
    for (int col = 0; col < size; col++)
    {
      renderBoard(row, col);
      switch (board.retPiece(row, col).getType() | board.retPiece(row, col).getColor())
      {
      case KING | BLACKn:
        renderPiece(KING_BLACK, col, row);
        break;
      case KING | WHITEn:
        renderPiece(KING_WHITE, col, row);
        break;
      case PAWN | BLACKn:
        renderPiece(PAWN_BLACK, col, row);
        break;
      case PAWN | WHITEn:
        renderPiece(PAWN_WHITE, col, row);
        break;
      case BISHOP | BLACKn:
        renderPiece(BISHOP_BLACK, col, row);
        break;
      case BISHOP | WHITEn:
        renderPiece(BISHOP_WHITE, col, row);
        break;
      case QUEEN | BLACKn:
        renderPiece(QUEEN_BLACK, col, row);
        break;
      case QUEEN | WHITEn:
        renderPiece(QUEEN_WHITE, col, row);
        break;
      case KNIGHT | BLACKn:
        renderPiece(KNIGHT_BLACK, col, row);
        break;
      case KNIGHT | WHITEn:
        renderPiece(KNIGHT_WHITE, col, row);
        break;
      case ROOK | BLACKn:
        renderPiece(ROOK_BLACK, col, row);
        break;
      case ROOK | WHITEn:
        renderPiece(ROOK_WHITE, col, row);
        break;
      }
    }
  }
  EndDrawing();
}

void ChessRenderer::renderBoard(const int row, const int col) const
{
  bool isLight = (row + col) % 2 == 0;
  if (isLight)
  {
    DrawRectangle(col * squaresize, row * squaresize, squaresize, squaresize, light);
  }
  if (!isLight)
  {
    DrawRectangle(col * squaresize, row * squaresize, squaresize, squaresize, dark);
  }
}

void ChessRenderer::renderPiece(const Texture2D pieceTexture, const int col, const int row) const
{
  Vector2 temp;
  temp.x = col * squaresize;
  temp.y = row * squaresize;
  DrawTextureEx(pieceTexture, temp, 0, 0.125, WHITE);
}

bool ChessRenderer::shouldClose() const
{
  return WindowShouldClose();
}

position ChessRenderer::handleMouseInput(bool& close)
{
  position aux = {-1, -1};
  bool click = false;
  while( click != true ){

    if(shouldClose() == true){
      close = true;
      break;
    }
    render();

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && IsCursorOnScreen())
    { 
      int X_pos = GetMouseX();
      int Y_pos = GetMouseY();
      int col = X_pos / squaresize;
      int row = Y_pos / squaresize;
      aux.row = row;
      aux.col = col;
      click = true;
    }
  }
  return aux;
}
