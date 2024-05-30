#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "PiecesDef.hpp"
#include "MoveDef.hpp"
#include <array>

namespace Candy{
    class Board {
    public:
        // constructor
        Board(int p_SizeBoard,SDL_Renderer* p_Renderer); // i will only drawSquare   
        // Public Function
        void drawBoard();
        void UpdatePlayer(Player p_Player); // handle player pieces hints
        int getPieceSize() const ;
    private:
        // Private Function
        void resetBoardColor();
        void SetHighlight(unsigned const int row, unsigned const int col);
        void showHints(Player p_Player);
        void showPieceHightlight(unsigned const int row, unsigned const int col);

        // hints pieces
       void WhitePawnHint();
       void BlackPawnHint();
       void KingHint();
       void QueenHint();
       void KnightHint();
       void RookHint();
       void BishopHint();
    private:
       // Private Variable 
        SDL_Renderer* m_Renderer;
        std::array<int, MAX_PIECES_SPACE  > m_Pieces;
        std::array<std::array<SDL_Color, MAX_PIECES_LINE>, MAX_PIECES_LINE> m_BoardColor;
        Player m_Player ;
        int m_PiecesSize = 75;
        int m_BoardSize;
    };
};



