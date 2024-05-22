  #include "../include/Board.hpp"
#include "../include/PiecesDef.hpp"
#include "../include/ColorDef.hpp"
  namespace Candy{
      void Board::resetBoardColor()
      {
          for (int row = 0; row < MAX_PIECES_LINE; row++)
          {
              for (int column = 0; column < MAX_PIECES_LINE; column++)
              {
                  //SDL_Color _color = 
                  if ((row + column) % 2 == 0)
                  {
                      m_BoardColor[row][column] = { Board_COlOR1 };
                  }
                  else 
                  {
                      m_BoardColor[row][column] = { Board_COlOR2 };
                  }
              }
          }
      }
      // i Want some after you select / hold a piece shows the which move are like this ^^^

      Board::Board(int p_SizeBoard , SDL_Renderer* p_Renderer)
          :m_BoardSize(p_SizeBoard) , m_Renderer(p_Renderer)
      {
          m_PiecesSize = m_BoardSize / MAX_PIECES_LINE;
          resetBoardColor();
          m_BoardColor[5][5] = { Green_COLOR };
      }

      void Board::drawBoard()
      {
         for (int row = 0; row < MAX_PIECES_LINE ; row++)
         {
             for (int column = 0 ; column< MAX_PIECES_LINE ; column++)
             {
                   SDL_Rect _block;
                   _block.x = column* m_PiecesSize;
                   _block.y = row* m_PiecesSize;
                   _block.w = _block.h = m_PiecesSize;

                  SDL_SetRenderDrawColor (m_Renderer, 
                                          m_BoardColor[row][column].r,
                                          m_BoardColor[row][column].g,
                                          m_BoardColor[row][column].b,
                                          m_BoardColor[row][column].a
                                         );
                  SDL_RenderFillRect(m_Renderer,&_block);
             }
         }

      }
      void Board::UpdatePlayer(Player p_Player)
      {
          if (p_Player.isSeleted == true) {
              m_BoardColor[p_Player.row][p_Player.col] = {Red_COLOR};
          }
          else {
              resetBoardColor();
          }
      }
      int Board::getPieceSize()
      {
          return m_PiecesSize;
      }
     
  };
