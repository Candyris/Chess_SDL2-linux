#include "../include/PiecesManger.hpp"
#include <iostream>  //for debug 

namespace Candy
{
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
        : m_Renderer(p_Renderer),m_BoardPieceSize(BoardSize/MAX_PIECES_LINE)
    {
        initDefaultBoard();
        for (int row = 0 ; row < MAX_PIECES_LINE ; row++)
        {
            for (int col = 0 ; col < MAX_PIECES_LINE ; col++)
            {
                std::cout<<"row: " <<row<<" col :"<<col<<std::endl;
                Piece* _piece;
                switch(m_BoardPieces[row][col])
                {
     case PIECES_TYPE::WHITE_KNIGHT:
     _piece = new Piece(m_Renderer,WHITE_KNIGHT_PATH,m_BoardPieceSize);
     _piece->setPosition(col * m_BoardPieceSize, row * m_BoardPieceSize);
      m_DrawPieces.push_back(_piece);                                            
      break;
                case PIECES_TYPE::BLACK_PAWN:
    _piece = new Piece(m_Renderer, BLACK_PAWN_PATH, m_BoardPieceSize);
    _piece->setPosition(col * m_BoardPieceSize, row * m_BoardPieceSize);
    m_DrawPieces.push_back(_piece);
    break;
case PIECES_TYPE::WHITE_PAWN:
    _piece = new Piece(m_Renderer, WHITE_PAWN_PATH, m_BoardPieceSize);
    _piece->setPosition(col * m_BoardPieceSize, row * m_BoardPieceSize);
    m_DrawPieces.push_back(_piece);
    break;
case PIECES_TYPE::WHITE_ROOK:
    _piece = new Piece(m_Renderer, WHITE_ROOK_PATH, m_BoardPieceSize);
    _piece->setPosition(col * m_BoardPieceSize, row * m_BoardPieceSize);
    m_DrawPieces.push_back(_piece);
    break;

case PIECES_TYPE::BLACK_ROOK:
    _piece = new Piece(m_Renderer, BLACK_ROOK_PATH, m_BoardPieceSize);
    _piece->setPosition(col * m_BoardPieceSize, row * m_BoardPieceSize);
    m_DrawPieces.push_back(_piece);
    break;
case PIECES_TYPE::BLACK_BISHOP:
    _piece = new Piece(m_Renderer, BLACK_BISHOP_PATH, m_BoardPieceSize);
    _piece->setPosition(col * m_BoardPieceSize, row * m_BoardPieceSize);
    m_DrawPieces.push_back(_piece);
    break;
case PIECES_TYPE::BLACK_KNIGHT:
    _piece = new Piece(m_Renderer, BLACK_KNIGHT_PATH, m_BoardPieceSize);
    _piece->setPosition(col * m_BoardPieceSize, row * m_BoardPieceSize);
    m_DrawPieces.push_back(_piece);
    break;
case PIECES_TYPE::BLACK_QUEEN:
    _piece = new Piece(m_Renderer, BLACK_QUEEN_PATH, m_BoardPieceSize);
    _piece->setPosition(col * m_BoardPieceSize, row * m_BoardPieceSize);
    m_DrawPieces.push_back(_piece);
    break;
case PIECES_TYPE::BLACK_KING:
    _piece = new Piece(m_Renderer, BLACK_KING_PATH, m_BoardPieceSize);
    _piece->setPosition(col * m_BoardPieceSize, row * m_BoardPieceSize);
    m_DrawPieces.push_back(_piece);
    break;
case PIECES_TYPE::WHITE_KING:
    _piece = new Piece(m_Renderer, WHITE_KING_PATH, m_BoardPieceSize);
    _piece->setPosition(col * m_BoardPieceSize, row * m_BoardPieceSize);
    m_DrawPieces.push_back(_piece);
    break;
case PIECES_TYPE::WHITE_QUEEN:
    _piece = new Piece(m_Renderer, WHITE_QUEEN_PATH, m_BoardPieceSize);
    _piece->setPosition(col * m_BoardPieceSize, row * m_BoardPieceSize);
    m_DrawPieces.push_back(_piece);
    break;
case PIECES_TYPE::WHITE_BISHOP:
    _piece = new Piece(m_Renderer, WHITE_BISHOP_PATH, m_BoardPieceSize);
    _piece->setPosition(col * m_BoardPieceSize, row * m_BoardPieceSize);
    m_DrawPieces.push_back(_piece);
    break;
// we free the memory right after  giving in the vector dont free here instead free in destructor like
                }
            }
        }
    }

    PiecesManger::~PiecesManger()
    {
        for (Piece* _piece : m_DrawPieces)
        {
            delete _piece;
            // here we freeing the memory
        }
    }



    void PiecesManger::drawPieces()
    {
        for (Piece* _piece : m_DrawPieces)
        {
            _piece->draw();
        }
    }

};
