#include "../include/PiecesDef.hpp"
  #include "../include/Board.hpp"
#include "../include/ColorDef.hpp"
#include <iostream> // for debug

/*
#pragma region Pawn
bool possibleMoveBlackPawn(const PiecePosition StartPos, const PiecePosition EndPos)
{
    if (0 <= StartPos.Row && StartPos.Row <= 7)
    {
        if (StartPos.Row + 1 == EndPos.Row) {
            if (0 == StartPos.Col)
            {
                if (EndPos.Col >= 0 && EndPos.Col <= StartPos.Col + 1)
                    return true;
            }
            else if (StartPos.Col == 7)// 7 is the last column of Board
            {
                if (EndPos.Col <= 7 && EndPos.Col >= StartPos.Col - 1)
                    return true;
            }
            else if (EndPos.Col > 0 && EndPos.Col < 7)
            {
                if ( StartPos.Col - 1 <= EndPos.Col&& EndPos.Col <= StartPos.Col + 1 )
                    return true;
            }
        }
        else if (StartPos.Row + 2 == EndPos.Row && StartPos.Row == 1)
        {
            if (StartPos.Col == EndPos.Col)
                return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

 bool possibleMoveWhitePawn(const PiecePosition StartPos, const PiecePosition EndPos)
{
    if (7 > StartPos.Row && StartPos.Row > 0)
    {
        if (StartPos.Row - 1 == EndPos.Row ) {
            if ( StartPos.Col == 0 )
            {
                if (EndPos.Col >= 0 && EndPos.Col <= StartPos.Col + 1)
                    return true;
            }
            else if (StartPos.Col == 7)// 7 is the last column of Board
            {
                if (EndPos.Col <= 7 && EndPos.Col >= StartPos.Col - 1)
                    return true;
            }
            else if (0 < StartPos.Col  && StartPos.Col < 7)
            {
                if (StartPos.Col - 1 <= EndPos.Col && EndPos.Col <= StartPos.Col + 1)
                    return true;
            }
            // later add condition for enspassant

            return false;
        }
        else if (StartPos.Row - 2 == EndPos.Row && StartPos.Row == 6)
        {
            if (StartPos.Col == EndPos.Col) // later add this condition from before
                return true;
        }
        else
        {
            return false;
        }
    }
    return false;

}
#pragma endregion
#pragma region King
 bool possibleMoveKing(const PiecePosition StartPos, const PiecePosition EndPos)
 {
     if (0 <= EndPos.Row && EndPos.Row <= 7 && 0 <= EndPos.Col && EndPos.Col <= 7)
     {
         if ((StartPos.Row + 1 >= EndPos.Row && EndPos.Row >= StartPos.Row - 1) &&
             (StartPos.Col + 1 >= EndPos.Col && EndPos.Col >= StartPos.Col - 1))
         {
             return true;
         }
     }
     return false;
 }
#pragma endregion
#pragma region Rook
 bool possibleMoveRook(const PiecePosition StartPos, const PiecePosition EndPos)
 {
     if (0 <= EndPos.Row && EndPos.Row <= 7 && 0 <= EndPos.Col && EndPos.Col <= 7)
     {
         if (StartPos.Col == EndPos.Col || StartPos.Row == EndPos.Row)
             return true;
     }
     return false;
 }
#pragma endregion
#pragma region Bishop
 bool possibleMoveBishop(const PiecePosition StartPos, const PiecePosition EndPos)
 {
     // first diagonal working
     if (0 <= EndPos.Row && EndPos.Row <= 7 && 0 <= EndPos.Col && EndPos.Col <= 7)
     {
         // well there is a problem with that i only checking for one diagonal other i dont have idea right now
         for (int col = StartPos.Col , row = StartPos.Row ; col <= 7 && row <= 7 ; col++,row++) // ok do it wrong way but still fun
         {
             std::cout << "COl     :" << col << ", ROW       :" << row << std::endl;
             std::cout << "OLD Col :" << EndPos.Col << ", OLD row :" << EndPos.Row << std::endl;

             if (col == EndPos.Col && row == EndPos.Row)
             {
                 return true;
             }
         }
         for (int col = StartPos.Col, row = StartPos.Row; col >= 0 && row >=0; col--, row--) // ok do it wrong way but still fun
         {
             std::cout << "COl :" << col << "ROW :" << row << std::endl;
             std::cout << "OLD Col :" << EndPos.Col << "OLD row :" << EndPos.Row << std::endl;
             if (col == EndPos.Col && row == EndPos.Row)
             {
                 return true;
             }
         }
         // second diagonal not working
         for (int col = StartPos.Col, row = StartPos.Row; col >= 0 && row <= 7; col--, row++) // ok do it wrong way but still fun
         {
             std::cout << "COl     :" << col << ", ROW       :" << row << std::endl;
             std::cout << "OLD Col :" << EndPos.Col << ", OLD row :" << EndPos.Row << std::endl;

             if (col == EndPos.Col && row == EndPos.Row)
             {
                 return true;
             }
         }
         for (int col = StartPos.Col, row = StartPos.Row; col <= 7 && row >= 0; col++, row--) // ok do it wrong way but still fun
         {
             std::cout << "COl :" << col << "ROW :" << row << std::endl;
             std::cout << "OLD Col :" << EndPos.Col << "OLD row :" << EndPos.Row << std::endl;
             if (col == EndPos.Col && row == EndPos.Row)
             {
                 return true;
             }
         }
     }
     // well now this working good 😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁😁
     return false;
 }
#pragma endregion
#pragma region Queen
 bool possibleMoveQueen(const PiecePosition StartPos, const PiecePosition EndPos)
 {
     if (0 <= EndPos.Row && EndPos.Row <= 7 && 0 <= EndPos.Col && EndPos.Col <= 7)
     {// well queen have same movement as bishop and rook combine
         if (possibleMoveRook(StartPos, EndPos) || possibleMoveBishop(StartPos, EndPos))
         {
             return true;
         }
     }
     return false;
 }
#pragma endregion
#pragma region Knight
 bool possibleMoveKnight(const PiecePosition StartPos, const PiecePosition EndPos)
 {
     if (0 <= EndPos.Row && EndPos.Row <= 7 && 0 <= EndPos.Col && EndPos.Col <= 7)
     {
         if (StartPos.Row -1 == EndPos.Row && StartPos.Col + -2 == EndPos.Col)
         {
             return true;
         }
         else if (StartPos.Row + 1 == EndPos.Row && StartPos.Col - 2 == EndPos.Col)
         {
             return true;
         }
         else if (StartPos.Row + 2 == EndPos.Row && StartPos.Col - 1 == EndPos.Col)
         {
             return true;
         }
         else if (StartPos.Row - 2 == EndPos.Row && StartPos.Col - 1 == EndPos.Col)
         {
             return true;
         }
         else if (StartPos.Row - 2 == EndPos.Row && StartPos.Col + 1 == EndPos.Col)
         {
             return true;
         }
         else if (StartPos.Row - 1 == EndPos.Row && StartPos.Col + 2 == EndPos.Col)
         {
             return true;
         }
         else if (StartPos.Row + 1 == EndPos.Row && StartPos.Col + 2 == EndPos.Col)
         {
             return true;
         }
         else if (StartPos.Row + 2 == EndPos.Row && StartPos.Col + 1 == EndPos.Col)
         {
             return true;
         }
     }
     return false;
 }


#pragma endregion

*/

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
          }
      }
      // I have added 
      // 
      // white Pawn hint and lets add other also
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
                          m_BoardColor[row - 1][i] = { Green_COLOR };
                      }
                  }
                  else if (StartPos.Col == 7)
                  {
                      for (int i = StartPos.Col - 1; i <= StartPos.Col;i++)
                      {
                          m_BoardColor[row - 1][i] = { Green_COLOR };
                      }
                  }
                  else if (StartPos.Col > 0 && StartPos.Col < 7)
                  {
                      for (int i = StartPos.Col - 1; i <= StartPos.Col + 1;i++)
                      {
                          m_BoardColor[row - 1][i] = { Green_COLOR };
                      }
                  }
                  if (StartPos.Row == 6)
                  {
                      m_BoardColor[row - 2][col] = { Green_COLOR };
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
                          m_BoardColor[row + 1][i] = { Green_COLOR };
                      }
                  }
                  else if (StartPos.Col == 7)
                  {
                      for (int i = StartPos.Col - 1; i <= StartPos.Col;i++)
                      {
                          m_BoardColor[row + 1][i] = { Green_COLOR };
                      }
                  }
                  else if (0 < StartPos.Col && StartPos.Col < 7)
                  {
                      for (int i = StartPos.Col - 1; i <= StartPos.Col + 1;i++)
                      {
                          m_BoardColor[row + 1][i] = { Green_COLOR };
                      }
                  }
                  // later add condition for enspassant


              }
              if (StartPos.Row == 1)
              {
                  m_BoardColor[row + 2][col] = { Green_COLOR };
              }
          }

      }
      // i have just box arround the king does the same 
      void Board::KingHint(const PiecePosition StartPos) {
          int row = StartPos.Row, col = StartPos.Col;

          if (row >= 0 && row <= 7 && col >= 0 && col <= 7) {

              for (int i = row - 1; i <= row + 1; i++) {
                  for (int j = col - 1; j <= col + 1; j++) {

                      if (i >= 0 && i <= 7 && j >= 0 && j <= 7) {
                          m_BoardColor[i][j] = { Green_COLOR };
                      }
                  }
              }
          }
      }

      void Board::KnightHint(const PiecePosition StartPos)
      {
          if (0 <= StartPos.Row && StartPos.Row <= 7 || 0 <= StartPos.Col && StartPos.Col<= 7)
          {
              if (StartPos.Row - 1 <= 7 && StartPos.Row - 1 >= 0 && StartPos.Col - 2 <= 7 && StartPos.Col - 2 >= 0)
              {
                  m_BoardColor[StartPos.Row - 1][StartPos.Col - 2] = { Green_COLOR };
              }

              if (StartPos.Row + 1 <= 7 && StartPos.Row + 1 >= 0 && StartPos.Col - 2 <= 7 && StartPos.Col - 2 >= 0)
              {
                  m_BoardColor[StartPos.Row + 1][StartPos.Col - 2] = { Green_COLOR };
              }
              if (StartPos.Row + 2 <= 7 && StartPos.Row + 2 >= 0 && StartPos.Col - 1 <= 7 && StartPos.Col - 1 >= 0)
              {
                  m_BoardColor[StartPos.Row + 2][StartPos.Col - 1] = { Green_COLOR };
              }
              if (StartPos.Row - 2 <= 7 && StartPos.Row - 2 >= 0 && StartPos.Col - 1 <= 7 && StartPos.Col - 1 >= 0)
              {
                  m_BoardColor[StartPos.Row - 2][StartPos.Col - 1] = { Green_COLOR };
              }
              if (StartPos.Row - 2 <= 7 && StartPos.Row - 2 >= 0 && StartPos.Col + 1 <= 7 && StartPos.Col + 1 >= 0)
              {
                  m_BoardColor[StartPos.Row - 2][StartPos.Col + 1] = { Green_COLOR };
              }
              if (StartPos.Row - 1 <= 7 && StartPos.Row - 1 >= 0 && StartPos.Col + 2 <= 7 && StartPos.Col + 2 >= 0)
              {
                  m_BoardColor[StartPos.Row - 1][StartPos.Col + 2] = { Green_COLOR };
              }
              if (StartPos.Row + 1 <= 7 && StartPos.Row + 1 >= 0 && StartPos.Col + 2 <= 7 && StartPos.Col + 2 >= 0)
              {
                  m_BoardColor[StartPos.Row + 1][StartPos.Col + 2] = { Green_COLOR };
              }
              if (StartPos.Row + 1 <= 7 && StartPos.Row + 1 >= 0 && StartPos.Col + 2 <= 7 && StartPos.Col + 2 >= 0)
              {
                  m_BoardColor[StartPos.Row + 1][StartPos.Col + 2] = { Green_COLOR };
              }
              if (StartPos.Row + 2 <= 7 && StartPos.Row + 2 >= 0 && StartPos.Col + 1 <= 7 && StartPos.Col + 1 >= 0)
              {
                  m_BoardColor[StartPos.Row + 2][StartPos.Col + 1] = { Green_COLOR };
              }
          }
      }
      
      void Board::RookHint(const PiecePosition StartPos)
      {
          if (0 <= StartPos.Row && StartPos.Row <= 7 || 0 <= StartPos.Col && StartPos.Col <= 7)
          {
              for (int i = 0; i <= 7;i++)
              {
                  m_BoardColor[i][StartPos.Col] = { Green_COLOR };
                  m_BoardColor[StartPos.Row][i] = { Green_COLOR };
              }
          }
      }
    // i have decided that lets finsh one more piece like rook 

      // i Want some after you select / hold a piece shows the which move are like this ^^^

      Board::Board(int p_SizeBoard , SDL_Renderer* p_Renderer)
          :m_BoardSize(p_SizeBoard) , m_Renderer(p_Renderer)
      {
          m_PiecesSize = m_BoardSize / MAX_PIECES_LINE;
          resetBoardColor();
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
      int Board::getPieceSize() const
      {
          return m_PiecesSize;
      }
     
  };
