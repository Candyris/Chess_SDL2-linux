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
        Piece(const char* p_FilePath,int p_PieceSize);
        Piece(){initVariable();}
        
        ~Piece(){}
        // functions that should use during in main Game
        void init(const char* p_FilePath,int p_PieceSize);
        void setPosition(int p_X ,int  p_Y);
        void setOrgin(int p_OffsetX , int p_OffsetY);
        void setTextureFromPath(const char* p_FilePath);
        void setPieceSize(int p_Size);

        void draw();

        // make it easy so all have same renderer 
        static SDL_Renderer *s_Renderer;
        static void setRenderer(SDL_Renderer* p_Renderer); 
        static SDL_Renderer* GetRenderer();
    private:
        SDL_Rect *m_PieceProperty;
        SDL_Texture* m_PieceTexture;
        int  m_OrginOffsetX;
        int  m_OrginOffsetY;
        void initVariable();
    };
};
