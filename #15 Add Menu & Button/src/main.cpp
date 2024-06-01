#include "../include/Game.hpp"
#include "../include/Menu.hpp"
const int g_WINDOW_WIDTH  = 600;
const int g_WINDOW_HEIGHT = 600;

static Candy::Game* gGame = nullptr;

inline void init();
inline void GameLoop();
inline void close();

int main(int argc , char * argv[])
{
    init();
    GameLoop();
    close();

    return 0;
}

inline void init(){
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG); // I am plaining on using PNG and JPEG picture
    TTF_Init();
    gGame = new Candy::Game("Chess", g_WINDOW_WIDTH, g_WINDOW_HEIGHT);
}



inline void GameLoop()
{
    Candy::Menu menu(gGame->getRenderer());
    bool MenuRunning = true;
    while (MenuRunning)
    {
        switch (menu.getMenuState())
        {
        case Menu_State::NONE:

            menu.DisplayMenu();
            break;

        case Menu_State::PLAY:
            gGame->resetGame();
            while (gGame->isRunning())
            {
                gGame->pollEvent();
                gGame->update();
                gGame->render();
                if (gGame->isRunning() == false)
                    break;
            }
            menu.DisplayGameOver(gGame->getWinner().c_str());
            break;
        case Menu_State::QUIT:
            MenuRunning = false;
            break;
        }
    }
}

inline void close()
{
    delete gGame;
    SDL_Quit();
    IMG_Quit();
}
// now we have successfully create window now lets do this class so we have make things easier
