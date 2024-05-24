#include "../include/PiecesDef.hpp"
  #include "../include/Board.hpp"
#include "../include/ColorDef.hpp"


  namespace Candy
  {

      // constructor
      Board::Board(int p_SizeBoard, SDL_Renderer* p_Renderer)
          :m_BoardSize(p_SizeBoard), m_Renderer(p_Renderer)
      {
          m_PiecesSize = m_BoardSize / MAX_PIECES_LINE;
          resetBoardColor();
      }

      // reseting color to default 
      void Board::resetBoardColor()
      {
          for (int row = 0; row < MAX_PIECES_LINE; row++)
          {
              for (int column = 0; column < MAX_PIECES_LINE; column++)
              {
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

      // this will decided on which tile color should be
      void Board::SetHighlight(unsigned const int row ,unsigned const int col)
      {
          if (((row + col) % 2) == 0)
          {
              m_BoardColor[row][col]={ Green_COLOR};
          }
          else 
          {
              m_BoardColor[row][col] = { DarkGreen_COLOR };
          }
      }

      // private functions that allow to calculate pieces highlight for possible moves
      void Board::showHints(Player p_Player)
      {
          int _pieceType = p_Player.BoardPieces[p_Player.row][p_Player.col];
          PiecePosition _pos(p_Player.row,p_Player.col);
          switch (_pieceType) 
          {
          case PIECES_TYPE::WHITE_PAWN:
              WhitePawnHint(_pos);
              break;
          case PIECES_TYPE::BLACK_PAWN:
              BlackPawnHint(_pos);
              break;
          
          case PIECES_TYPE::BLACK_KING:
              KingHint(_pos);
              break;
          case PIECES_TYPE::WHITE_KING:
              KingHint(_pos);
              break;
          case PIECES_TYPE::BLACK_KNIGHT:
              KnightHint(_pos);
              break;
          case PIECES_TYPE::WHITE_KNIGHT:
              KnightHint(_pos);
              break;
          case PIECES_TYPE::BLACK_ROOK:
              RookHint(_pos);
              break;
          case PIECES_TYPE::WHITE_ROOK:
              RookHint(_pos);
              break;
          case PIECES_TYPE::BLACK_BISHOP:
              BishopHint(_pos);
              break;
          case PIECES_TYPE::WHITE_BISHOP:
              BishopHint(_pos);
              break;
          case PIECES_TYPE::BLACK_QUEEN:
              QueenHint(_pos);
              break;
          case PIECES_TYPE::WHITE_QUEEN:
              QueenHint(_pos);
              break;
          }
      }
      
      // all pieces highlight calculate functions
      void Board::WhitePawnHint(PiecePosition StartPos)
      {
          int col = StartPos.Col, row = StartPos.Row;
          if (0 <= StartPos.Row && StartPos.Row <= 7)
          {
              if (StartPos.Row > 0)
              {
                  if (0 == StartPos.Col)
                  {
                      for (int i = StartPos.Col; i <= StartPos.Col + 1;i++)
                      {
                          SetHighlight(row - 1, i);
                      }
                  }
                  else if (StartPos.Col == 7)
                  {
                      for (int i = StartPos.Col - 1; i <= StartPos.Col;i++)
                      {
                          SetHighlight(row - 1, i);
                      }
                  }
                  else if (StartPos.Col > 0 && StartPos.Col < 7)
                  {
                      for (int i = StartPos.Col - 1; i <= StartPos.Col + 1;i++)
                      {
                          SetHighlight(row - 1, i);
                      }
                  }
                  if (StartPos.Row == 6)
                  {
                      SetHighlight(row - 2, col);
                  }
              }
          }
      }
      void Board::BlackPawnHint(const PiecePosition StartPos) // some range after 7 row fix later
      {
          int col = StartPos.Col, row = StartPos.Row;

          if (0 <= StartPos.Row && StartPos.Row <= 7)
          {
              if (StartPos.Row < 7) {
                  if (StartPos.Col == 0)
                  {
                      for (int i = StartPos.Col; i <= StartPos.Col + 1;i++)
                      {
                          SetHighlight(row + 1,i);
                      }
                  }
                  else if (StartPos.Col == 7)
                  {
                      for (int i = StartPos.Col - 1; i <= StartPos.Col;i++)
                      {
                          SetHighlight(row + 1, i); 
                      }
                  }
                  else if (0 < StartPos.Col && StartPos.Col < 7)
                  {
                      for (int i = StartPos.Col - 1; i <= StartPos.Col + 1;i++)
                      {
                          SetHighlight(row + 1,i);
                      }
                  }
                  // later add condition for enspassant


              }
              if (StartPos.Row == 1)
              {
                  SetHighlight(row + 2,col);
              }
          }

      }
      
      void Board::KingHint(const PiecePosition StartPos) {
          int row = StartPos.Row, col = StartPos.Col;

          if (row >= 0 && row <= 7 && col >= 0 && col <= 7) {

              for (int i = row - 1; i <= row + 1; i++) {
                  for (int j = col - 1; j <= col + 1; j++) {

                      if (i >= 0 && i <= 7 && j >= 0 && j <= 7) {
                          SetHighlight(i, j); 
                      }
                  }
              }
          }
      }
      void Board::QueenHint(const PiecePosition StartPos)
      {
          BishopHint(StartPos);
          RookHint(StartPos);
      }
      void Board::KnightHint(const PiecePosition StartPos)
      {
          if (0 <= StartPos.Row && StartPos.Row <= 7 || 0 <= StartPos.Col && StartPos.Col<= 7)
          {
              if (StartPos.Row - 1 <= 7 && StartPos.Row - 1 >= 0 && StartPos.Col - 2 <= 7 && StartPos.Col - 2 >= 0)
              {
                  SetHighlight(StartPos.Row - 1,StartPos.Col - 2);
              }

              if (StartPos.Row + 1 <= 7 && StartPos.Row + 1 >= 0 && StartPos.Col - 2 <= 7 && StartPos.Col - 2 >= 0)
              {
                  SetHighlight(StartPos.Row + 1, StartPos.Col - 2);
              }
              if (StartPos.Row + 2 <= 7 && StartPos.Row + 2 >= 0 && StartPos.Col - 1 <= 7 && StartPos.Col - 1 >= 0)
              {
                  SetHighlight(StartPos.Row + 2, StartPos.Col - 1);
              }
              if (StartPos.Row - 2 <= 7 && StartPos.Row - 2 >= 0 && StartPos.Col - 1 <= 7 && StartPos.Col - 1 >= 0)
              {
                  SetHighlight(StartPos.Row - 2, StartPos.Col - 1);
              }
              if (StartPos.Row - 2 <= 7 && StartPos.Row - 2 >= 0 && StartPos.Col + 1 <= 7 && StartPos.Col + 1 >= 0)
              {
                  SetHighlight(StartPos.Row - 2, StartPos.Col + 1);
              }
              if (StartPos.Row - 1 <= 7 && StartPos.Row - 1 >= 0 && StartPos.Col + 2 <= 7 && StartPos.Col + 2 >= 0)
              {
                  SetHighlight(StartPos.Row - 1, StartPos.Col + 2);
              }
              if (StartPos.Row + 1 <= 7 && StartPos.Row + 1 >= 0 && StartPos.Col + 2 <= 7 && StartPos.Col + 2 >= 0)
              {
                  SetHighlight(StartPos.Row + 1, StartPos.Col + 2);
              }
              if (StartPos.Row + 1 <= 7 && StartPos.Row + 1 >= 0 && StartPos.Col + 2 <= 7 && StartPos.Col + 2 >= 0)
              {
                  SetHighlight(StartPos.Row + 1, StartPos.Col + 2);
              }
              if (StartPos.Row + 2 <= 7 && StartPos.Row + 2 >= 0 && StartPos.Col + 1 <= 7 && StartPos.Col + 1 >= 0)
              {
                  SetHighlight(StartPos.Row + 2, StartPos.Col + 1);
              }
          }
      }
      
      void Board::RookHint(const PiecePosition StartPos)
      {
          if (0 <= StartPos.Row && StartPos.Row <= 7 || 0 <= StartPos.Col && StartPos.Col <= 7)
          {
              for (int i = 0; i <= 7;i++)
              {
                  SetHighlight(i, StartPos.Col);
                  SetHighlight(StartPos.Row, i);
              }
          }
      }
      void Board::BishopHint(const PiecePosition StartPos)
      {
          for (int col = StartPos.Col, row = StartPos.Row; col <= 7 && row <= 7; col++, row++) // ok do it wrong way but still fun
          {
              SetHighlight(row, col);
          }
          for (int col = StartPos.Col, row = StartPos.Row; col >= 0 && row >= 0; col--, row--) // ok do it wrong way but still fun
          {
              SetHighlight(row,col);
          }
          // second diagonal not working
          for (int col = StartPos.Col, row = StartPos.Row; col >= 0 && row <= 7; col--, row++) // ok do it wrong way but still fun
          {

              SetHighlight(row,col);
          }
          for (int col = StartPos.Col, row = StartPos.Row; col <= 7 && row >= 0; col++, row--) // ok do it wrong way but still fun
          {
              SetHighlight(row,col);
          }
      }

      // public functions for handle tasks according object
      void Board::UpdatePlayer(Player p_Player)
      {
          if (p_Player.isSeleted == true) {
              showHints(p_Player);
              m_BoardColor[p_Player.row][p_Player.col] = {Red_COLOR}; // i like some like this 
          }
          else {
              resetBoardColor();
          }
      }
      void Board::drawBoard()
      {
         for (int row = 0; row < MAX_PIECES_LINE ; row++)
         {
             for (int column = 0 ; column< MAX_PIECES_LINE ; column++)
             {
                 SDL_Rect _block = {};

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

      // getter
      int Board::getPieceSize() const
      {
          return m_PiecesSize;
      }
     
  };
