  #include "../include/Pieces.hpp"
  #include "../include/TextureManger.hpp"
#include <cstddef>
  #include <iostream> // debug
 
namespace Candy{
    // static Renderer stuff  
    SDL_Renderer* Piece::s_Renderer = NULL;
    
    void Piece::setRenderer(SDL_Renderer* p_Renderer)
    {
        s_Renderer = p_Renderer;
    }
     SDL_Renderer* Piece::GetRenderer()
     {
         return s_Renderer;
     }
    
     void Piece::initVariable()
     {
        m_PieceProperty = new SDL_Rect({});
        m_PieceTexture = NULL;
        m_OrginOffsetX = 0;
        m_OrginOffsetY = 0;
     }
     Piece::Piece(const char* p_FilePath,int p_PieceSize) 
     {
         initVariable();
         init(p_FilePath,p_PieceSize);
     }
    void Piece::init(const char* p_FilePath,int p_PieceSize)
    {
        m_PieceTexture = TextureManger::GetTexture(GetRenderer(),p_FilePath);
        m_PieceProperty->w = m_PieceProperty->h = p_PieceSize; 
    }
    void Piece::setPosition(int p_X,int  p_Y)
    {
        m_PieceProperty->x = p_X + m_OrginOffsetX;
        m_PieceProperty->y = p_Y + m_OrginOffsetY;
    }
    void Piece::setOrgin(int p_OffsetX , int p_OffsetY)
    {
        m_OrginOffsetX = p_OffsetX;
        m_OrginOffsetY = p_OffsetY;
    }
    void Piece::setTextureFromPath(const char* p_FilePath)
    {
        m_PieceTexture = TextureManger::GetTexture(GetRenderer(),p_FilePath);
    }
    void Piece::setPieceSize(int p_Size)
    {
        m_PieceProperty->w = m_PieceProperty->h = p_Size;    
    }
    
    void Piece::draw()
    {
         TextureManger::Render(GetRenderer(), m_PieceTexture, m_PieceProperty);
         if (m_PieceTexture) 
         {
              TextureManger::Render(GetRenderer(), m_PieceTexture, m_PieceProperty);
         } else {
              std::cerr << "Cannot draw piece, texture is NULL" << std::endl;
         }
    }


};
