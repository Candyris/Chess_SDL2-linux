#pragma once
#include <SDL2/SDL.h>
#include "Pieces.hpp"
#include "Board.hpp"
#include <array>

namespace Candy {
    class PiecesManger {
    public:
        PiecesManger(SDL_Renderer* p_Renderer, int BoardSize);
        ~PiecesManger(){}

        void CalculatePieces();
        void drawPieces();
        void updateBoardPieces(int* p_MouseX,int* p_MouseY);
        void isPieceSelect(bool p_state,int* p_MouseX,int* p_MouseY);

        void setSize(int p_PieceSize);
    private:
        void init();
        void initDefaultBoard();
        void addPiece(const char* p_FilePath, int row, int col);

        SDL_Renderer* m_Renderer;

        int m_BoardPieceSize;
        bool m_PieceSelectState;
        int m_LastPiece_Row;
        int m_LastPiece_Col;

        Piece** m_DrawPieces;
        std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> m_BoardPieces;
    };
}

//#endif // PIECESMANGER_HPP

