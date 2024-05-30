#pragma once
#include <SDL2/SDL.h>
#include "PiecesDef.hpp"

namespace Candy{
    class Piece
    {
    public:
        Piece(const char* p_FilePath,int p_PieceSize);
        Piece(){initVariable();}
        
        ~Piece(){}
        // functions that should use during in main Game
        void init(const char* p_FilePath,int p_PieceSize);
        void setPosition(int p_X ,int  p_Y);
        void setOrgin(int p_OffsetX , int p_OffsetY);
        void setTextureFromPath(const char* p_FilePath);
        void setPieceSize(int p_Size);
        // For debug the error 
        void Log();
        void draw();

        // make it easy so all have same renderer 
        static SDL_Renderer *s_Renderer;
        static void setRenderer(SDL_Renderer* p_Renderer); 
        static SDL_Renderer* GetRenderer();
    private:
        SDL_Rect *m_PieceProperty;
        SDL_Texture* m_PieceTexture;
        bool m_CancelDraw;
        int  m_OrginOffsetX;
        int  m_OrginOffsetY;
        void initVariable();
    };
};
