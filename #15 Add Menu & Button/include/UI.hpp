#pragma once 
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
namespace Candy {
	class UI 
	{
	public:
		void init_UI(SDL_Renderer* ren,SDL_Color color , SDL_Rect rect);
		// setter
		void setColor(int r, int g,int b,int a);
		void setPosition(int x , int y);
		void setSize(int w , int h);

		// getter
		SDL_Rect getRect()const;

		virtual void render() = 0;
	protected:
		// Later inhert to the derived class
		SDL_Color UI_Color = {};
		SDL_Rect UI_Box = {};
		SDL_Renderer* UI_Renderer = NULL;
		SDL_Texture* UI_Texture = NULL;
	};
};