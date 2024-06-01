#include "../include/Button.hpp"
#include <SDL2/SDL_ttf.h>
#include "../include/TextureManger.hpp"
#include <iostream>

void Candy::Button::initButton()
{
	m_FontPath = "";
	m_FontSize = DEFAULTBUTTON_FONT_SIZE;

	UI_Box = {};
	m_ButtonTextColor = { 123,44,55,255 };
	UI_Color = { 0,0,0, 255 };
	m_ButtonTextTexture = NULL;
}

Candy::Button::Button(SDL_Renderer* p_Renderer, std::string text, const char* filename)
{
	int _ButtonSize = text.size();
	initButton();
	init_UI(p_Renderer, { 0,0,0,255}, { 0,0,300,100});
	m_FontPath = filename;
	m_ButtonText = text;
	createTextTexture(m_FontPath.c_str(), text.c_str());
}

Candy::Button::~Button()
{
	SDL_DestroyTexture(m_ButtonTextTexture);
}

void Candy::Button::render()
{
	// Drawing the button Text
	if (UI_Texture == NULL)
	{
		SDL_SetRenderDrawColor(UI_Renderer, UI_Color.r, UI_Color.g, UI_Color.b, UI_Color.a );
		SDL_RenderFillRect(UI_Renderer, &UI_Box);
		// Drawing the button Text
		SDL_RenderCopy(UI_Renderer, m_ButtonTextTexture, NULL, &UI_Box);
	}
	else 
	{
		// Drawing the button box 
		SDL_RenderCopy(UI_Renderer, UI_Texture, NULL, &UI_Box);
		// Drawing the button Text
		SDL_RenderCopy(UI_Renderer, m_ButtonTextTexture, NULL, &UI_Box);
		std::cout << SDL_GetError() << std::endl;
	}
}

bool Candy::Button::IsButtonClick(SDL_Event* event)
{
		if (event->type == SDL_MOUSEBUTTONUP)
		{
			if (SDL_BUTTON_LEFT == event->button.button)
			{
				int x,  y;
				SDL_GetMouseState(&x, &y);
				if ((UI_Box.x < x && x < UI_Box.x + UI_Box.w) &&
					(UI_Box.y < y && y < UI_Box.y + UI_Box.h))
				{
					return true;
				}
			}
		}
	return false;
}

void Candy::Button::setTexture(const char* filename)
{
	UI_Texture = TextureManger::GetTexture(UI_Renderer, filename);
	if (UI_Texture == NULL)
	{
		SDL_Log("Failed in loading the texture to button  PATH ->%s",filename);
	}
}

void Candy::Button::setText(const char* Text)
{
	m_ButtonText = Text;
	createTextTexture(m_FontPath.c_str(), m_ButtonText.c_str());
}

void Candy::Button::setFont(const char* filePath)
{
	m_FontPath = filePath;
	createTextTexture(m_FontPath.c_str(), m_ButtonText.c_str());
}

void Candy::Button::setFontSize(const int& size)
{
	m_FontSize = size;
	createTextTexture(m_FontPath.c_str(), m_ButtonText.c_str());
}

void Candy::Button::setRect(SDL_Rect& rect)
{
	UI_Box = rect;
}

void Candy::Button::setPosition(int x, int y)
{
	UI_Box.x = x;
	UI_Box.y = y;
}



void Candy::Button::createTextTexture(const char* p_FontPath,const char* p_Text)
{
	TTF_Font* _font = TTF_OpenFont(p_FontPath, m_FontSize);

	SDL_Surface* _surface = TTF_RenderText_Solid(_font,p_Text,m_ButtonTextColor);

	m_ButtonTextTexture = SDL_CreateTextureFromSurface(UI_Renderer, _surface);
	if (m_ButtonTextTexture == NULL)
	{
		SDL_Log("Failed to create Text Texture!!" );
	}
	SDL_Log("Error::BUTTON::TEXT %s ", SDL_GetError());
	TTF_CloseFont(_font);
	SDL_FreeSurface(_surface);

}



