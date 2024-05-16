#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Board.hpp"
#include "Pieces.hpp"

namespace Candy
{
    class Game
    {
    public:
        Game(const char* p_Title, int p_Width,int p_Height);
        ~Game();
        void update();
        void pollEvent();
        bool isRunning()const;
        void render();
    private:
        void init();
        void drawBoard();
        bool m_Running = false;

        Board* m_Board;
        bool m_Is_Selected; 
        SDL_Window* m_Window;
        SDL_Renderer* m_Renderer;
        SDL_Event* m_Event;
        Piece* m_WPawn;
    };
};

