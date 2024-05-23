#include "../include/Game.hpp"
#include <SDL2/SDL_timer.h>
#include <iostream> // for debugging 
                    //
namespace Candy{
    void Game::init()
    {
        m_Event = new SDL_Event;
        m_Window = NULL;
        m_Renderer = NULL;
        m_Running = true;
        m_Is_Selected = false;
    }
    Game::Game(const char* p_Title, int p_Width,int p_Height)
    {
       init();
       m_Window = SDL_CreateWindow(p_Title, SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
                                    p_Width, p_Height, SDL_WINDOW_SHOWN);
       m_Renderer = SDL_CreateRenderer(m_Window,-1, SDL_RENDERER_PRESENTVSYNC);
       m_Board = new Board(p_Height,m_Renderer);
       m_WPawn = new Piece(m_Renderer,WHITE_KING_PATH,75);
       std::cout<<"Successful in Construtor "<<std::endl;
       m_WPawn->setPosition(100, 100);
       m_BoardPieces = new PiecesManger(m_Renderer,p_Height); 
    }
    Game::~Game()
    {
        delete m_WPawn;
        delete m_Board;
        delete m_Event;
        SDL_DestroyRenderer(m_Renderer);
        SDL_DestroyWindow(m_Window);
    }
    bool  Game::isRunning() const
    {
        return m_Running;
    }
    void Game::pollEvent()
    {
        while (SDL_PollEvent(m_Event))
          {
              switch (m_Event->type)
              {
                case SDL_QUIT:
                  m_Running = false;
                  break;
                 case SDL_MOUSEBUTTONDOWN:
                    switch(m_Event->button.button)
                    {
                        case SDL_BUTTON_LEFT:
                            m_Is_Selected = true;
                          int x , y ;
                          SDL_GetMouseState(&x, &y);
                          m_WPawn->setPosition(x,y);
                        break;
                    }
                    break;
                case SDL_MOUSEBUTTONUP:
                        m_Is_Selected = false;
                    
              }
          }
    }
    void Game::update()
    {
        // lets add some movement
        if (m_Is_Selected)
        {
            int x , y ;
            SDL_GetMouseState(&x,&y);
            x -= 35; // offsetx
            y -= 35; // offsety
            m_WPawn->setPosition(x, y);
        }
    }
    void Game::render()
    {
        // Setting BackGround Winodow Color 
         SDL_SetRenderDrawColor(m_Renderer,255,255,0,255);
        // clearing Winodw from previous drawn objects
        SDL_RenderClear(m_Renderer);
        // draw from their
         m_Board->drawBoard();
         m_BoardPieces->drawPieces();
        m_WPawn->draw();
        SDL_RenderPresent(m_Renderer);
    }

     


};
