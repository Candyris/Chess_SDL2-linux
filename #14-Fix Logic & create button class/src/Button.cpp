#include "../include/Button.hpp"
#include <SDL2/SDL_ttf.h>
#include <iostream>
Candy::Button::Button(SDL_Renderer* p_Renderer, std::string text, const char* filename, const SDL_Color p_Color)
{
	int _ButtonSize = text.size();
	initButton();
	init_UI(p_Renderer, { DEFAULTBUTTON_COLOR }, { 100,200,300,100});
	m_ButtonTextColor = p_Color;
	createTextTexture(filename, text.c_str());
}

Candy::Button::~Button()
{
	SDL_DestroyTexture(m_ButtonTextTexture);
}

void Candy::Button::render()
{
	SDL_RenderCopy(UI_Renderer, m_ButtonTextTexture, NULL, &UI_Box);
}

void Candy::Button::initButton()
{
	m_ButtonTextColor = {DEFAULTBUTTON_COLOR};
	m_ButtonTextSize = { DEFAULTBUTTON_FONT_SIZE };
	m_ButtonTextTexture = NULL;
}

void Candy::Button::createTextTexture(const char* p_FontPath,const char* p_Text)
{
	TTF_Font* _font = TTF_OpenFont(p_FontPath, m_ButtonTextSize);

	SDL_Surface* _surface = TTF_RenderText_Solid(_font,p_Text,m_ButtonTextColor);

	m_ButtonTextTexture = SDL_CreateTextureFromSurface(UI_Renderer, _surface);
	if (m_ButtonTextTexture == NULL)
	{
		SDL_Log("Failed to create Texture!!" );
	}
	TTF_CloseFont(_font);
	SDL_FreeSurface(_surface);

}



