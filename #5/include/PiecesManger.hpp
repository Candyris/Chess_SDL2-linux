#pragma once
#include <SDL2/SDL.h>
#include "Pieces.hpp"
#include "Board.hpp"
#include <array>

namespace PIECES_TYPE {
    const int EMPTY = 0;
    const int WHITE_KING = 1;
    const int WHITE_QUEEN = 2;
    const int WHITE_ROOK = 3;
    const int WHITE_BISHOP = 4;
    const int WHITE_KNIGHT = 5;
    const int WHITE_PAWN = 6;
    const int BLACK_KING = -1;
    const int BLACK_QUEEN = -2;
    const int BLACK_ROOK = -3;
    const int BLACK_BISHOP = -4;
    const int BLACK_KNIGHT = -5;
    const int BLACK_PAWN = -6;
};

namespace Candy {
    class PiecesManger {
    public:
        PiecesManger(SDL_Renderer* p_Renderer, int BoardSize);
        ~PiecesManger(){}

        void CalculatePieces();
        void drawPieces();
        void updateBoardPieces();
        void isPieceSelect(bool p_state);
    private:
        void init();
        void initDefaultBoard();
        void addPiece(const char* p_FilePath, int row, int col);

        SDL_Renderer* m_Renderer;

        int m_BoardPieceSize;
        bool m_PieceSelectState;
        int m_LastPiece_Row;
        int m_LastPiece_Col;

        std::array<std::array<Piece,MAX_PIECES_LINE>,MAX_PIECES_LINE> m_DrawPieces;
        std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> m_BoardPieces;
    };
}

//#endif // PIECESMANGER_HPP

