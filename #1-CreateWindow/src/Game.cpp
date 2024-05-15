#include "../include/Game.hpp"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

namespace Candy{
    void Game::init()
    {
        m_Event = new SDL_Event;
        m_Window = NULL;
        m_Renderer = NULL;
        m_Running = true;
    }
    Game::Game(const char* p_Title, int p_Width,int p_Height)
    {
       init();
       m_Window = SDL_CreateWindow(p_Title, SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
                                    p_Width, p_Height, SDL_WINDOW_SHOWN);
       m_Renderer = SDL_CreateRenderer(m_Window,-1, SDL_RENDERER_PRESENTVSYNC);

    }
    Game::~Game()
    {
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
              switch (m_Event->type){
                case SDL_QUIT:
                  m_Running = false;
                  break;
              }
          }
    }
    void Game::update()
    {

    }
    void Game::render()
    {
        // Setting BackGround Winodow Color 
        SDL_SetRenderDrawColor(m_Renderer,255,255,0,255);
        // clearing Winodw from previous drawn objects
        SDL_RenderClear(m_Renderer);
        // draw all objects
        //SDL_RenderCopy(SDL_Renderer *renderer, SDL_Texture *texture, const SDL_Rect *srcrect, const SDL_Rect *dstrect);
        SDL_RenderPresent(m_Renderer);
    }


};
