#include "../include/PiecesManger.hpp"
//#include <iostream>

namespace Candy
{
    void PiecesManger::init()
    {
        m_LastPiece_Col = -1;
        m_LastPiece_Row = -1;
        m_PieceSelectState = false;
        m_BoardPieces = {};
    }

    void PiecesManger::initDefaultBoard()
    {
        m_BoardPieces =
        {
           -5,-4,-3,-2,-1,-3,-4,-5,
           -6,-6,-6,-6,-6,-6,-6,-6,
            0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0,
            6, 6, 6, 6, 6, 6, 6, 6,
            5, 4, 3, 2, 1, 3, 4, 5
        };
    }

    PiecesManger::PiecesManger(SDL_Renderer* p_Renderer,int BoardSize)
          : m_Renderer(p_Renderer), m_BoardPieceSize(BoardSize/MAX_PIECES_LINE)
      {
           Piece::s_Renderer = m_Renderer;
          init();
          initDefaultBoard();
          CalculatePieces();
      }


    void PiecesManger::addPiece(const char* p_FilePath, int row, int col) {

        m_DrawPieces[row][col].setTextureFromPath(p_FilePath);
        m_DrawPieces[row][col].setPosition((col * m_BoardPieceSize) ,
                             (row * m_BoardPieceSize));
    }

    void PiecesManger::CalculatePieces()
    {
        for (int row = 0 ; row < MAX_PIECES_LINE ; row++)
        {
            for (int col = 0 ; col < MAX_PIECES_LINE ; col++)
            {
                switch(m_BoardPieces[row][col])
                {
                    case PIECES_TYPE::WHITE_KNIGHT:
                        addPiece(WHITE_KNIGHT_PATH,row,col);
                    break;
                    case PIECES_TYPE::BLACK_PAWN:
                        addPiece(BLACK_PAWN_PATH,row,col);
                    break;
                    case PIECES_TYPE::WHITE_PAWN:
                        addPiece(WHITE_PAWN_PATH,row,col);
                     break;
                    case PIECES_TYPE::WHITE_ROOK:
                        addPiece(WHITE_ROOK_PATH,row,col);
                     break;
                    case PIECES_TYPE::BLACK_ROOK:
                         addPiece(BLACK_ROOK_PATH,row,col);
                     break;
                     case PIECES_TYPE::BLACK_BISHOP:
                         addPiece(BLACK_BISHOP_PATH,row,col);
                     break;
                     case PIECES_TYPE::BLACK_KNIGHT:
                          addPiece(BLACK_KNIGHT_PATH,row,col);
                     break;
                     case PIECES_TYPE::BLACK_QUEEN:
                          addPiece(BLACK_QUEEN_PATH,row,col);
                     break;
                     case PIECES_TYPE::BLACK_KING:
                         addPiece(BLACK_KING_PATH,row,col);
                      break;
                      case PIECES_TYPE::WHITE_KING:
                         addPiece(WHITE_KING_PATH,row,col);
                      break;
                      case PIECES_TYPE::WHITE_QUEEN:
                         addPiece(WHITE_QUEEN_PATH,row,col);
                      break;
                      case PIECES_TYPE::WHITE_BISHOP:
                         addPiece(WHITE_BISHOP_PATH,row,col);
                     break;
                }
                }
        }
    }

    void PiecesManger::drawPieces() 
    {
        for (int row = 0; row < MAX_PIECES_LINE ;row++)
        {
            for (int col = 0 ; col < MAX_PIECES_LINE; col++)
            {
                m_DrawPieces[row][col].draw();
            }
        }
    }

    void PiecesManger::updateBoardPieces()
    {
        if (m_PieceSelectState)
        {
            int _x , _y;
            SDL_GetMouseState(&_x,&_y);
            m_DrawPieces[m_LastPiece_Row][m_LastPiece_Col].setPosition(_x,_y);
        }
    }

    void PiecesManger::isPieceSelect(bool p_state)
    {
        int _x , _y;
        SDL_GetMouseState(&_x,&_y);
        if (p_state == true)
        {
            //CalculatePieces();
            m_PieceSelectState = true;
            m_LastPiece_Col = _x/MAX_PIECES_LINE;
            m_LastPiece_Row = _y/MAX_PIECES_LINE;

        }
        else if (p_state == false)
        {
            m_PieceSelectState = false;
            int  _newRow = _y / MAX_PIECES_LINE;
            int  _newCol = _x / MAX_PIECES_LINE;
            m_BoardPieces[_newRow][_newCol] =  m_BoardPieces[m_LastPiece_Row][m_LastPiece_Col];

           CalculatePieces();
        }
    }
}

