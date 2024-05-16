#pragma once 
#include "Pieces.hpp"
#include <SDL2/SDL_render.h>
#include <vector>
#include "Board.hpp"
#include <array>
namespace PIECES_TYPE{
   const int BLACK_PAWN   = -6 ;
   const int BLACK_ROOK   = -5 ;
   const int BLACK_BISHOP = -4 ;
   const int BLACK_KNIGHT = -3 ;
   const int BLACK_QUEEN  = -2 ;
   const int BLACK_KING   = -1 ;
   const int PIECE_NONE   = 0 ;
   const int WHITE_KING   = 1 ;
   const int WHITE_QUEEN  = 2 ;
   const int WHITE_KNIGHT = 3 ;
   const int WHITE_BISHOP = 4 ;
   const int WHITE_ROOK   = 5 ; 
   const int WHITE_PAWN   = 6 ;
  };

namespace Candy{
    class PiecesManger 
    {
    public:
        PiecesManger(SDL_Renderer* p_Renderer,int BoardSize);
        ~PiecesManger();
        void drawPieces();

    private:
        int m_BoardPieceSize;
        SDL_Renderer* m_Renderer;
        std::array<std::array<int,MAX_PIECES_LINE>,MAX_PIECES_LINE> m_BoardPieces;
        // 64 Pieces 
        void initDefaultBoard();
        std::vector<Piece*> m_DrawPieces;  
    };

};
