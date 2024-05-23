#include "../include/Pieces.hpp"
#include "../include/TextureManger.hpp"
namespace Candy 
{
    void Piece::init()
    {
        m_PieceProperty = new SDL_Rect;
        *m_PieceProperty = {};
        m_PieceTexture =NULL;
    }
    Piece::Piece(SDL_Renderer* p_Renderer,const char* p_FilePath,int p_PieceSize)
        : m_Renderer(p_Renderer)
    {
        init();
        // so this means that this problem causing this
        m_PieceTexture = TextureManger::GetTexture(m_Renderer,p_FilePath);
        m_PieceProperty->w =  p_PieceSize;
        // so this is the problem

        m_PieceProperty->h = p_PieceSize;
    }
    Piece::~Piece()
    {
        delete m_PieceProperty;
        if (m_PieceTexture != NULL)
        {
            SDL_DestroyTexture(m_PieceTexture);
        }
    }

    void Piece::setPosition(int p_X , int p_Y)
    {
        m_PieceProperty->x = p_X;
        m_PieceProperty->y = p_Y;
    }
    void Piece::draw()
    {
        TextureManger::Render(m_Renderer,m_PieceTexture,m_PieceProperty);
       // SDL_RenderCopy(m_Renderer, m_PieceTexture, NULL, m_PieceProperty);
    }
    

};
