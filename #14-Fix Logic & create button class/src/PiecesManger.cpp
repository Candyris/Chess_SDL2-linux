﻿#include "../include/PiecesManger.hpp"
#include "../include/PiecesDef.hpp"
#include "../include/Moves.hpp"
#include <iostream>
namespace Candy
{
    void PiecesManger::init()
    {
        m_IsLastBlackMove = false;
        m_LastPiece_Col = -1;
        m_LastPiece_Row = -1;
        m_PieceSelectState = false;
        m_BoardPieces.fill({PIECES_TYPE::EMPTY});
        m_DrawPieces = new Piece*[MAX_PIECES_LINE];
        for (int i = 0; i < MAX_PIECES_LINE; ++i) {
            m_DrawPieces[i] = new Piece[MAX_PIECES_LINE];
        }
    }

    void PiecesManger::initDefaultBoard()
    {
        m_BoardPieces = {{
            {{ -5, -4, -3, -2, -1, -3, -4, -5 }},
            {{ -6, -6, -6, -6, -6, -6, -6, -6 }},
            {{  0,  0,  0,  0,  0,  0,  0,  0 }},
            {{  0,  0,  0,  0,  0,  0,  0,  0 }},
            {{  0,  0,  0,  0,  0,  0,  0,  0 }},
            {{  0,  0,  0,  0,  0,  0,  0,  0 }},
            {{  6,  6,  6,  6,  6,  6,  6,  6 }},
            {{  5,  4,  3,  2,  1,  3,  4,  5 }}
        }};
    }

    bool PiecesManger::isBlack()
    {
        return (m_BoardPieces[m_LastPiece_Row][m_LastPiece_Col] < 0);
    }
    
    PiecesManger::PiecesManger(SDL_Renderer* p_Renderer,int BoardSize)
          : m_Renderer(p_Renderer), m_BoardPieceSize(BoardSize/MAX_PIECES_LINE)
      {
           Piece::s_Renderer = m_Renderer;
          init();
          initDefaultBoard();
          CalculatePieces();
            for (int row = 0 ; row < MAX_PIECES_LINE ; row++)
                for (int col =0 ; col < MAX_PIECES_LINE ; col++)
                    m_DrawPieces[row][col].setPieceSize(m_BoardPieceSize);
                    // m_DrawPieces[row][col].setOrgin(+m_BoardPieceSize/2,+m_BoardPieceSize/2);
          }
      
    void PiecesManger::addPiece(const char* p_FilePath, int row, int col)
    {

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
                         break; // so this fixed
                      case PIECES_TYPE::EMPTY:
                          m_DrawPieces[row][col].setTextureFromPath(EMPTY_PATH);
                          m_DrawPieces[row][col].setPosition((col * m_BoardPieceSize),
                              (row * m_BoardPieceSize));
                     break;
                     default:
                        break;
                }
                }
        }
    }
    void PiecesManger::setSize(int p_PieceSize)
    {
       m_BoardPieceSize = p_PieceSize;
    }
    void PiecesManger::GameOver()
    {
        bool WhiteKing = false;
        bool BlackKing = false;
        for (int row = 0; row < MAX_PIECES_LINE; row++)
        {
            for (int col = 0; col < MAX_PIECES_LINE; col++)
            {
                if (m_BoardPieces[row][col] == PIECES_TYPE::WHITE_KING)
                {
                    std::cout << "White King is Alive ^_^" << std::endl;
                    WhiteKing = true;
                }
                if (m_BoardPieces[row][col] == PIECES_TYPE::BLACK_KING)
                {
                    std::cout << "Black King is Alive ^_^" << std::endl;
                    BlackKing = true;
                }

            }
        }
        if (!WhiteKing)
        {
            std::cout << "White is lose U_U" << std::endl;
        }
        if (!BlackKing)
        {
            std::cout << "Black is lose U_U" << std::endl;
        }
    }
    Player PiecesManger::getPlayer() const 
    {
        Player _player(m_BoardPieces);
        _player.isSeleted = m_PieceSelectState;
        _player.row = m_LastPiece_Row;
        _player.col = m_LastPiece_Col;

        return _player;
    }
    void PiecesManger::drawPieces() 
    {
        for (int row = 0; row < MAX_PIECES_LINE ;row++)
        {
            for (int col = 0 ; col < MAX_PIECES_LINE; col++)
            {
              //  m_DrawPieces[row][col].Log();
                m_DrawPieces[row][col].draw();
                //std::cout<<"drawing position"<<row << " , "<<col<< std::endl;
            }
        }
    }

    void PiecesManger::updateBoardPieces(int* p_MouseX,int* p_MouseY)
    {
        int _X = *p_MouseX - m_BoardPieceSize / 2;
        int _Y = *p_MouseY - m_BoardPieceSize / 2;
        if (m_PieceSelectState)
        {
            m_DrawPieces[m_LastPiece_Row][m_LastPiece_Col].setPosition(_X ,_Y );
        }
    }

    void PiecesManger::isPieceSelect(bool p_state,int* p_MouseX,int* p_MouseY)
    {
        if (p_state)
        {
            m_PieceSelectState = true;
            m_LastPiece_Col = *p_MouseX/m_BoardPieceSize; // width
            m_LastPiece_Row = *p_MouseY/m_BoardPieceSize; // height

        }
        else if (!p_state)
        {
            m_PieceSelectState = false;
            int  _newCol= *p_MouseX / m_BoardPieceSize;
            int  _newRow = *p_MouseY / m_BoardPieceSize;

            bool _tempColor = m_IsLastBlackMove;

            // fix error regarding empty of the piece
            if (Moves::VaildMove(m_BoardPieces, PiecePosition(m_LastPiece_Row, m_LastPiece_Col), PiecePosition(_newRow, _newCol)) && (m_BoardPieces[m_LastPiece_Row][m_LastPiece_Col] != PIECES_TYPE::EMPTY))
            {
                if (m_IsLastBlackMove == isBlack())
                {
                    m_BoardPieces[_newRow][_newCol] =  m_BoardPieces[m_LastPiece_Row][m_LastPiece_Col] ; 
                    _tempColor = !m_IsLastBlackMove;
                }
            }
            else 
            {
                _newRow = m_LastPiece_Row;
                _newCol = m_LastPiece_Col;
            }
            if ((m_LastPiece_Col != _newCol || m_LastPiece_Row != _newRow ))
            {
                if (m_IsLastBlackMove == isBlack())
                {
                    m_BoardPieces[m_LastPiece_Row][m_LastPiece_Col] = PIECES_TYPE::EMPTY;
                }
            }
            m_IsLastBlackMove = _tempColor;
            CalculatePieces();
            GameOver();
            //m_DrawPieces[m_LastPiece_Row][m_LastPiece_Col].setTextureFromPath(EMPTY_PATH);

        }
    }
}


