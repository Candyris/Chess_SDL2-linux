#pragma once
#include "UI.hpp"
#include "ButtonDef.hpp"
#include <string>



namespace Candy {
    class Button : public UI
    {
    public:
        Button(SDL_Renderer* p_Renderer, std::string text,const char* filename, const SDL_Color p_Color = { DEFAULTBUTTON_COLOR });
        ~Button();
        void render();

        // Setter
       //void setText();
       //void setFont();


        // Getter

    private:
        void initButton();
        void createTextTexture(const char* p_FontPath, const char* p_Text);
        std::string m_Text;
        int m_ButtonTextSize;
        SDL_Texture* m_ButtonTextTexture;
        SDL_Color m_ButtonTextColor;

    };
};
