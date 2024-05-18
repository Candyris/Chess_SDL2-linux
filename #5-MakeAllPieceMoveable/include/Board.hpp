#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
//#include <array>

#define MAX_PIECES_SPACE 64
#define MAX_PIECES_LINE 8
#define MAX_DIFFERENT_TYPES_PIECES16
namespace Candy{
    class Board {
    public:
            Board(int p_SizeBoard,SDL_Renderer* p_Renderer); // i will only drawSquare     
            void drawBoard();
            int getPieceSize();
    private:
            SDL_Renderer* m_Renderer;
           // std::array<int,MAX_PIECES_SPACE  > m_Pieces;
            int m_PiecesSize = 75;
            int m_BoardSize;
    };
};



