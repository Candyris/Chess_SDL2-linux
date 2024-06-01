#pragma once
#include <string>
#include <SDL2/SDL.h>
#include "Pieces.hpp"
#include "Board.hpp"
#include <array>
namespace Candy {
    class PiecesManger {
    public:
        // constructor and destoryer
        PiecesManger(SDL_Renderer* p_Renderer, int BoardSize);
        ~PiecesManger(){}

        // Public Functions (main funtions)
        void drawPieces();
        void resetPieces();
        void updateBoardPieces(int* p_MouseX,int* p_MouseY);
        void isPieceSelect(bool p_state,int* p_MouseX,int* p_MouseY);

    public:
        // Setter
        void setSize(int p_PieceSize);
        std::string GameOver();

        // Getter
        Player getPlayer() const ;

    private:
        // Private Functions 
        void init();
        void initDefaultBoard();
        bool isBlack();
        void addPiece(const char* p_FilePath, int row, int col);
        void CalculatePieces();


    private:
        // Private Variables
        SDL_Renderer* m_Renderer;
        int m_BoardPieceSize;
        bool m_PieceSelectState;
        int m_LastPiece_Row;
        int m_LastPiece_Col;
        bool m_IsLastBlackMove = 1;
        Piece** m_DrawPieces;
        std::array<std::array<int, MAX_PIECES_LINE>, MAX_PIECES_LINE> m_BoardPieces;
    };
}

//#endif // PIECESMANGER_HPP

