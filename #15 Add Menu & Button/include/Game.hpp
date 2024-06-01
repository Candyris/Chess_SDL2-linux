#pragma once
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Board.hpp"
#include "PiecesManger.hpp"
#include "Button.hpp"
namespace Candy
{
    class Game
    {
    public:
        // Public Functions (main functions)
        Game(const char* p_Title, int p_Width,int p_Height);
        ~Game();
        void update();
        void pollEvent();
        bool isRunning()const;
        void resetGame();
        void render();
        std::string getWinner(){ return m_BoardPieces->GameOver(); }

        // getter
        SDL_Renderer* getRenderer()const;
        SDL_Window* getWindow()const { return m_Window; }
    private:
        // Private Functions
        void init();
        void updateMousePosition();
        void getMousePosition(int* x,int * y);
    private:
        // Private Variable
        bool m_Is_Selected;
        int *m_CurrentmouseX;
        int *m_CurrentmouseY;
        bool m_Running = false;

        //class/struct type varible and gfx
        SDL_Window* m_Window;
        SDL_Renderer* m_Renderer;
        SDL_Event* m_Event;
        Board* m_Board;
        PiecesManger* m_BoardPieces;
    };
};

