#pragma once
#include <SDL2/SDL.h>

// TextureManger := Is the class for handle the texture creation from the file path
//                 And Is the class for handle the draw from Texture
namespace Candy{
    class TextureManger
    {
    public:
        static SDL_Texture* GetTexture(SDL_Renderer* p_Renderer,const char* p_FilePath);
        static void Render(SDL_Renderer* p_Renderer,SDL_Texture* p_Texture,SDL_Rect* p_DsntRect);
    };
};
