#pragma once
#include "UI.hpp"
#include "ButtonDef.hpp"
#include <string>

namespace Candy {
    class Button : public UI
    {
    public:
        // Public Functions (main Functions)
        Button(SDL_Renderer* p_Renderer, std::string text,const char* filename);
        ~Button();
        void render() override;

        bool IsButtonClick(SDL_Event* event);

    public:
        // Setter
        void setTexture(const char* filename);
        void setText(const char* Text);
        void setFont(const char* filePath);
        void setFontSize(const int& size);
        void setRect(SDL_Rect& rect);
        void setPosition(int x, int y);
        // Getter
        
    private:
        // Private Functions
        void initButton();
        void createTextTexture(const char* p_FontPath, const char* p_Text);
    private:
        // Private Variables
        std::string m_ButtonText;
        std::string m_FontPath;
        int m_FontSize;
        SDL_Texture* m_ButtonTextTexture;
        SDL_Color m_ButtonTextColor;

    };
};
