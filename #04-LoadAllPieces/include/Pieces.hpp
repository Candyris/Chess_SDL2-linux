#pragma once
#include <SDL2/SDL.h>

// BLACK Piece PATH

#define BLACK_PAWN_PATH "assets/Pieces_IMG/Chess_pawnBlack60.png"
#define BLACK_BISHOP_PATH "assets/Pieces_IMG/Chess_bishipBlack60.png"
#define BLACK_KNIGHT_PATH "assets/Pieces_IMG/Chess_knightBlack60.png"
#define BLACK_ROOK_PATH "assets/Pieces_IMG/Chess_rookBlack60.png"
#define BLACK_QUEEN_PATH "assets/Pieces_IMG/Chess_queenBlack60.png"
#define BLACK_KING_PATH "assets/Pieces_IMG/Chess_kingBlack60.png"

// WHITE Piece PATH

#define WHITE_PAWN_PATH "assets/Pieces_IMG/Chess_pawnWhite60.png"
#define WHITE_BISHOP_PATH "assets/Pieces_IMG/Chess_bishipWhite60.png"
#define WHITE_KNIGHT_PATH "assets/Pieces_IMG/Chess_knightWhite60.png"
#define WHITE_ROOK_PATH "assets/Pieces_IMG/Chess_rookWhite60.png"
#define WHITE_QUEEN_PATH "assets/Pieces_IMG/Chess_queenWhite60.png"
#define WHITE_KING_PATH "assets/Pieces_IMG/Chess_kingWhite60.png"  

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
