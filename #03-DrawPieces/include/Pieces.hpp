#pragma once
#include <SDL2/SDL.h>

#define BLACK_PAWN_PATH "assets/Pieces_IMG/Chess_pawnBlack60.png"
#define WHITE_PAWN_PATH "assets/Pieces_IMG/Chess_pawnWhite60.png"
#define IMG "ai-generated-8707694_1280.png"
namespace Candy{
    class Piece
    {
    public:
        Piece(SDL_Renderer* p_Renderer,const char* p_FilePath,int p_PieceSize);
        ~Piece();
        void setPosition(int p_X ,int  p_Y);
        void draw();
    private:
        SDL_Renderer *m_Renderer; // don't know the error for 
        SDL_Rect *m_PieceProperty; // don't know
        SDL_Texture* m_PieceTexture;
        void init();
    };
};
