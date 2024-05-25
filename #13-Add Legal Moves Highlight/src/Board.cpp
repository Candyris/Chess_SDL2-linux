#include "../include/PiecesDef.hpp"
  #include "../include/Board.hpp"
#include "../include/ColorDef.hpp"
#include <iostream>

static bool round(int num)
{
    return (num > 0);
}

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
              WhitePawnHint();
              break;
          case PIECES_TYPE::BLACK_PAWN:
              BlackPawnHint(p_Player.BoardPieces, _pos);
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

      void Board::showPieceHightlight(unsigned const int row, unsigned const int col)
      {
          m_BoardColor[row][col] = { Red_COLOR };
      }
      
      // all pieces highlight calculate functions
      void Board::WhitePawnHint()
      {
          // first all bad move wrting and set to false 
          if (m_Player.row < 1 || m_Player.row > 6 || m_Player.col < 0 || m_Player.col > 7 )
          {
              return ;
          }
          // write the one step move for all
          if (m_Player.BoardPieces[m_Player.row - 1][m_Player.col] == PIECES_TYPE::EMPTY && m_Player.row >= 0 && m_Player.row <= 7)
          {
              SetHighlight(m_Player.row - 1, m_Player.col);
          }
          // write the two step move for all
          if (m_Player.row == 6 && m_Player.row >= 0 && m_Player.row <= 7)
          {
              if (m_Player.BoardPieces[m_Player.row - 1][m_Player.col] == PIECES_TYPE::EMPTY) {
                  if (m_Player.BoardPieces[m_Player.row - 2][m_Player.col] == PIECES_TYPE::EMPTY)
                  {
                      SetHighlight(m_Player.row - 2, m_Player.col);
                  }
              }
          }
          // write to capture diagonal 
          // FIRST  diagonal 
          if (m_Player.col >= 1)
          {
              if ((m_Player.BoardPieces[m_Player.row - 1][m_Player.col - 1] != PIECES_TYPE::EMPTY))
              {
                  if (m_Player.BoardPieces[m_Player.row - 1][m_Player.col -1] < 0)
                  {
                  showPieceHightlight(m_Player.row - 1, m_Player.col - 1);
                  }
              }
          }
          // SECOND diagonal 
          if (m_Player.col <= 6)
          {
              if ((m_Player.BoardPieces[m_Player.row - 1][m_Player.col + 1] != PIECES_TYPE::EMPTY))
              {
                  if (m_Player.BoardPieces[m_Player.row - 1][m_Player.col + 1] < 0)
                  {
                  showPieceHightlight(m_Player.row - 1, m_Player.col + 1);
                  }
              }
          }
      } // this Working alright 
      void Board::BlackPawnHint(std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> p_PieceBoard, const PiecePosition StartPos) // some range after 7 row fix later
      {
          // first all bad move wrting and set to false 
          if (m_Player.row < 0|| m_Player.row > 7 || m_Player.col < 0 || m_Player.col > 7)
          {
              return;
          }
          // write the one step move for all
          if (m_Player.BoardPieces[m_Player.row + 1][m_Player.col] == PIECES_TYPE::EMPTY && m_Player.row >= 0 && m_Player.row <= 7)
          {
              SetHighlight(m_Player.row + 1, m_Player.col);
          }
          // write the two step move for all
          if (m_Player.row == 1 && m_Player.row >= 0 && m_Player.row <= 7)
          {
              if (m_Player.BoardPieces[m_Player.row + 1][m_Player.col] == PIECES_TYPE::EMPTY)
              {
                  if (m_Player.BoardPieces[m_Player.row + 2][m_Player.col] == PIECES_TYPE::EMPTY)
                  {
                      SetHighlight(m_Player.row + 2, m_Player.col);
                  }
              }
          }
          // write to capture diagonal 
          // FIRST  diagonal 
          if (m_Player.col >= 1)
          {
              if ((m_Player.BoardPieces[m_Player.row + 1][m_Player.col - 1] != PIECES_TYPE::EMPTY) )
              {
                  if (m_Player.BoardPieces[m_Player.row + 1][m_Player.col - 1] > 0)
                  {
                      showPieceHightlight(m_Player.row + 1, m_Player.col - 1);
                  }
              }
          }
          // SECOND diagonal 
          if (m_Player.col <= 6) //  dont know why it is not working fix it later or may be behind the recording and check the answer or what in source code 
          {
              if ((m_Player.BoardPieces[m_Player.row + 1][m_Player.col + 1] != PIECES_TYPE::EMPTY) )
              {
                  if (m_Player.BoardPieces[m_Player.row + 1][m_Player.col + 1] > 0)
                  {
                      showPieceHightlight(m_Player.row + 1, m_Player.col + 1);
                  }
              }
          }

      }      
      void Board::KingHint(const PiecePosition StartPos) {
          int row = StartPos.Row, col = StartPos.Col;
          int pieceColor = round(m_Player.BoardPieces[m_Player.row][m_Player.col]);
          if (row >= 0 && row <= 7 && col >= 0 && col <= 7) {

              for (int i = row - 1; i <= row + 1; i++) {
                  for (int j = col - 1; j <= col + 1; j++) {

                      if (i >= 0 && i <= 7 && j >= 0 && j <= 7) 
                      {
                          if (m_Player.BoardPieces[i][j] == PIECES_TYPE::EMPTY )
                          {
                              SetHighlight(i,j);
                          }
                          else {
                              if (round(m_Player.BoardPieces[i][j]) != pieceColor)
                                showPieceHightlight(i,j);
                          }
                      }
                  }
              }
          }
      } // this is working 
      void Board::QueenHint(const PiecePosition StartPos)
      {
          BishopHint(StartPos);
          RookHint(StartPos);
      }
      void Board::KnightHint(const PiecePosition StartPos)
      {
          if (0 <= StartPos.Row && StartPos.Row <= 7 || 0 <= StartPos.Col && StartPos.Col<= 7)
          {
              int pieceColor = round(m_Player.BoardPieces[m_Player.row][m_Player.col]);

              if (StartPos.Row - 1 <= 7 && StartPos.Row - 1 >= 0 && StartPos.Col - 2 <= 7 && StartPos.Col - 2 >= 0)
              {
                  if (round(m_Player.BoardPieces[m_Player.row - 1][m_Player.col - 2]) != pieceColor && m_Player.BoardPieces[m_Player.row - 1][m_Player.col - 2] != PIECES_TYPE::EMPTY)
                      showPieceHightlight(m_Player.row - 1, m_Player.col - 2);
                  else
                      if (m_Player.BoardPieces[m_Player.row - 1][m_Player.col - 2] == PIECES_TYPE::EMPTY)
                      {
                          SetHighlight(m_Player.row - 1, m_Player.col - 2);
                      }
              }
              if (StartPos.Row + 1 <= 7 && StartPos.Row + 1 >= 0 && StartPos.Col - 2 <= 7 && StartPos.Col - 2 >= 0)
              {
                  if (round(m_Player.BoardPieces[m_Player.row + 1][m_Player.col - 2]) != pieceColor && m_Player.BoardPieces[m_Player.row + 1][m_Player.col - 2] != PIECES_TYPE::EMPTY)
                      showPieceHightlight(m_Player.row + 1, m_Player.col - 2);
                  else
                      if (m_Player.BoardPieces[m_Player.row + 1][m_Player.col - 2] == PIECES_TYPE::EMPTY)
                      {
                          SetHighlight(m_Player.row + 1, m_Player.col - 2);
                      }
              }
              if (StartPos.Row + 2 <= 7 && StartPos.Row + 2 >= 0 && StartPos.Col - 1 <= 7 && StartPos.Col - 1 >= 0)
              {
                  if (round(m_Player.BoardPieces[m_Player.row + 2][m_Player.col - 1]) != pieceColor  && m_Player.BoardPieces[m_Player.row + 2][m_Player.col - 1] != PIECES_TYPE::EMPTY)
                      showPieceHightlight(m_Player.row + 2, m_Player.col - 1);
                  else
                      if (m_Player.BoardPieces[m_Player.row + 2][m_Player.col - 1] == PIECES_TYPE::EMPTY)
                      {
                          SetHighlight(m_Player.row + 2, m_Player.col - 1);
                      }
              }
              if (StartPos.Row - 2 <= 7 && StartPos.Row - 2 >= 0 && StartPos.Col - 1 <= 7 && StartPos.Col - 1 >= 0 )
              {
                  if (round(m_Player.BoardPieces[m_Player.row - 2][m_Player.col - 1]) != pieceColor && m_Player.BoardPieces[m_Player.row - 2][m_Player.col - 1] != PIECES_TYPE::EMPTY)
                      showPieceHightlight(m_Player.row - 2, m_Player.col - 1);
                  else
                      if (m_Player.BoardPieces[m_Player.row - 2][m_Player.col - 1] == PIECES_TYPE::EMPTY)
                      {
                          SetHighlight(m_Player.row - 2, m_Player.col - 1);
                      }
              }
              if (StartPos.Row - 2 <= 7 && StartPos.Row - 2 >= 0 && StartPos.Col + 1 <= 7 && StartPos.Col + 1 >= 0 )
              {
                  if (round(m_Player.BoardPieces[m_Player.row - 2][m_Player.col + 1]) != pieceColor && m_Player.BoardPieces[m_Player.row - 2][m_Player.col + 1] != PIECES_TYPE::EMPTY)
                      showPieceHightlight(m_Player.row - 2 , m_Player.col + 1);
                  else
                      if (m_Player.BoardPieces[m_Player.row - 2][m_Player.col + 1] == PIECES_TYPE::EMPTY)
                      {
                          SetHighlight(m_Player.row - 2, m_Player.col + 1);
                      }
              }
              if (StartPos.Row - 1 <= 7 && StartPos.Row - 1 >= 0 && StartPos.Col + 2 <= 7 && StartPos.Col + 2 >= 0 )
              {
                  if (round(m_Player.BoardPieces[m_Player.row - 1][m_Player.col + 2]) != pieceColor && m_Player.BoardPieces[m_Player.row - 1][m_Player.col + 2] != PIECES_TYPE::EMPTY)
                      showPieceHightlight(m_Player.row - 1, m_Player.col + 2);
                  else
                      if (m_Player.BoardPieces[m_Player.row - 1][m_Player.col + 2] == PIECES_TYPE::EMPTY)
                      {
                          SetHighlight(m_Player.row - 1, m_Player.col + 2);
                      }
              }
              if (StartPos.Row + 1 <= 7 && StartPos.Row + 1 >= 0 && StartPos.Col + 2 <= 7 && StartPos.Col + 2 >= 0 )
              {
                  if (round(m_Player.BoardPieces[m_Player.row + 1][m_Player.col + 2]) != pieceColor && m_Player.BoardPieces[m_Player.row + 1][m_Player.col + 2] != PIECES_TYPE::EMPTY)
                      showPieceHightlight(m_Player.row + 1, m_Player.col + 2);
                  else
                      if (m_Player.BoardPieces[m_Player.row + 1][m_Player.col + 2] == PIECES_TYPE::EMPTY)
                      {
                          SetHighlight(m_Player.row + 1, m_Player.col + 2);
                      }
              }
              if (StartPos.Row + 1 <= 7 && StartPos.Row + 1 >= 0 && StartPos.Col + 2 <= 7 && StartPos.Col + 2 >= 0 )
              {
                  if (round(m_Player.BoardPieces[m_Player.row + 1][m_Player.col + 2]) != pieceColor && m_Player.BoardPieces[m_Player.row + 1][m_Player.col + 2] != PIECES_TYPE::EMPTY)
                      showPieceHightlight(m_Player.row + 1, m_Player.col + 2);
                  else
                      if (m_Player.BoardPieces[m_Player.row + 1][m_Player.col + 2] == PIECES_TYPE::EMPTY)
                      {
                          SetHighlight(m_Player.row + 1, m_Player.col + 2);
                      }
              }
              if (StartPos.Row + 2 <= 7 && StartPos.Row + 2 >= 0 && StartPos.Col + 1 <= 7 && StartPos.Col + 1 >= 0)
              {
                  if (round(m_Player.BoardPieces[m_Player.row + 2][m_Player.col + 1]) != pieceColor && m_Player.BoardPieces[m_Player.row + 2][m_Player.col + 1] != PIECES_TYPE::EMPTY)
                      showPieceHightlight(m_Player.row + 2, m_Player.col + 1);
                  else
                      if (m_Player.BoardPieces[m_Player.row + 2][m_Player.col + 1] == PIECES_TYPE::EMPTY)
                      {
                          SetHighlight(m_Player.row + 2, m_Player.col + 1);
                      }
              }
          }
      }      
      void Board::RookHint(const PiecePosition StartPos) // half fix 
      {
          // first all bad move wrting and set to false 
          if (m_Player.row < 0 || m_Player.row > 7 || m_Player.col < 0 || m_Player.col > 7 )
          {
              return ;
          }
          int pieceColor = round(m_Player.BoardPieces[m_Player.row][m_Player.col]);

          // write all from position of rook up with row
              for (int i = m_Player.row - 1; i >= 0; i--)
              {
                  if (m_Player.BoardPieces[i][m_Player.col] == PIECES_TYPE::EMPTY) 
                  {
                      SetHighlight(i, m_Player.col);
                  }
                  if (m_Player.BoardPieces[i][m_Player.col] != PIECES_TYPE::EMPTY) 
                  {
                      if (round(m_Player.BoardPieces[i][m_Player.col]) != pieceColor)
                        showPieceHightlight(i, m_Player.col);
                  }
                  if (m_Player.BoardPieces[i][m_Player.col] != PIECES_TYPE::EMPTY)
                  {
                      break;
                  }

              }
              // write all from position of rook down with row
              for (int i = m_Player.row + 1; i <= 7; i++)
              {
                  if (m_Player.BoardPieces[i][m_Player.col] == PIECES_TYPE::EMPTY)
                  {
                      SetHighlight(i, m_Player.col);
                  }
                  if (m_Player.BoardPieces[i][m_Player.col] != PIECES_TYPE::EMPTY) 
                  {
                      if (round(m_Player.BoardPieces[i][m_Player.col]) != pieceColor)
                        showPieceHightlight(i, m_Player.col);
                  }
                  if (m_Player.BoardPieces[i][m_Player.col] != PIECES_TYPE::EMPTY)
                  {
                      break;
                  }
              }
              
          // write all from position of rook right with col
          
              for (int i = m_Player.col - 1; i >= 0; i--)
              {
                  if (m_Player.BoardPieces[m_Player.row][i] == PIECES_TYPE::EMPTY)
                  {
                      SetHighlight(m_Player.row, i);
                  }
                  if (m_Player.BoardPieces[m_Player.row][i] != PIECES_TYPE::EMPTY)
                  {
                      if (round(m_Player.BoardPieces[m_Player.row][i]) != pieceColor)
                        showPieceHightlight(m_Player.row, i);
                  }
                  if (m_Player.BoardPieces[m_Player.row][i] != PIECES_TYPE::EMPTY)
                  {
                      break;
                  }

              }
              // write all from position of rook right with col
              for (int i = m_Player.col + 1; i <= 7; i++)
              {
                  if (m_Player.BoardPieces[m_Player.row][i] == PIECES_TYPE::EMPTY)
                  {
                      SetHighlight(m_Player.row, i);
                  }
                  if (m_Player.BoardPieces[m_Player.row][i] != PIECES_TYPE::EMPTY)
                  {
                      if (round(m_Player.BoardPieces[m_Player.row][i]) != pieceColor)
                          showPieceHightlight(m_Player.row, i);
                  }
                  if (m_Player.BoardPieces[m_Player.row][i] != PIECES_TYPE::EMPTY)
                  {
                      break;
                  }
              }
      }
      void Board::BishopHint(const PiecePosition StartPos)
      {
          // first all bad move wrting and set to false 
          if (m_Player.row < 0 || m_Player.row > 7 || m_Player.col < 0 || m_Player.col > 7)
          {
              return ;
          }
          int pieceColor = round(m_Player.BoardPieces[m_Player.row][m_Player.col]);
          // local declaration of row and col
          int _row = 0, _col = 0;
          // Diagonal 1 upper
          _row = StartPos.Row - 1;
          _col = StartPos.Col - 1;
          while (_row >= 0 && _col >= 0)
          {
              if (m_Player.BoardPieces[_row][_col] == PIECES_TYPE::EMPTY) 
              {
                  SetHighlight(_row, _col);
              }
              if (m_Player.BoardPieces[_row][_col] != PIECES_TYPE::EMPTY)
              {
                  if (round(m_Player.BoardPieces[_row][_col]) != pieceColor)
                  {
                      showPieceHightlight(_row, _col);
                  }
                  break;
              }
              _row--; _col--;

          }
          // Diagonal 1 lower
          _row = StartPos.Row + 1;
          _col = StartPos.Col + 1;
          while (_row <= 7 && _col <= 7)
          {
              if (m_Player.BoardPieces[_row][_col] == PIECES_TYPE::EMPTY)
              {
                  SetHighlight(_row, _col);
              }
              if (m_Player.BoardPieces[_row][_col] != PIECES_TYPE::EMPTY)
              {
                  if (round(m_Player.BoardPieces[_row][_col]) != pieceColor)
                  {
                      showPieceHightlight(_row, _col);
                  }
                  break;
              }
              _row++; _col++;

          }
          // first diagonal is working 😁😁
          //Diagonal 2 upper
          _row = StartPos.Row - 1;
          _col = StartPos.Col + 1;
          while (_row >= 0 && _col <= 7)
          {
              if (m_Player.BoardPieces[_row][_col] == PIECES_TYPE::EMPTY)
              {
                  SetHighlight(_row, _col);
              }
              if (m_Player.BoardPieces[_row][_col] != PIECES_TYPE::EMPTY)
              {
                  if (round(m_Player.BoardPieces[_row][_col]) != pieceColor)
                  {
                      showPieceHightlight(_row, _col);
                  }
                  break;
              }
              _row--; _col++;
          }
          // Diagonal 2 lower
          _row = StartPos.Row + 1;
          _col = StartPos.Col - 1;
          while (_row <= 7 && _col >= 0)
          {
              if (m_Player.BoardPieces[_row][_col] == PIECES_TYPE::EMPTY)
              {
                  SetHighlight(_row, _col);
              }
              if (m_Player.BoardPieces[_row][_col] != PIECES_TYPE::EMPTY)
              {
                  if (round(m_Player.BoardPieces[_row][_col]) != pieceColor)
                  {
                      showPieceHightlight(_row, _col);
                  }
                  break;
              }
              _row++; _col--;

          }
      }

      // public functions for handle tasks according object
      void Board::UpdatePlayer(Player p_Player)
      {
          m_Player = p_Player;
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
