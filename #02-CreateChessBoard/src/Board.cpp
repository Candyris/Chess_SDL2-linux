  #include "../include/Board.hpp"


  namespace Candy{
      Board::Board(int p_SizeBoard , SDL_Renderer* p_Renderer)
          :m_BoardSize(p_SizeBoard) , m_Renderer(p_Renderer)
      {
          m_PiecesSize = m_BoardSize / MAX_PIECES_LINE;

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
                  if ((row+column)%2 == 0)
                  {
                       SDL_SetRenderDrawColor  (m_Renderer, 255,255,255,255);
                   }else{
                        SDL_SetRenderDrawColor (m_Renderer, 0,0,0,255);
                   }
                  SDL_RenderFillRect(m_Renderer,&_block);
             }
         }

      }
  };
