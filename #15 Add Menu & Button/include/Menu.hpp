#pragma once 
#include <string>
#include "Button.hpp"
#include "MenuDef.hpp"
#include <vector>

namespace Candy 
{
	class Menu
	{
	public:
		Menu(SDL_Renderer* p_Renderer);
		void DisplayMenu();
		void DisplayGameOver(std::string p_Winner);
		void Update(SDL_Window* p_Window);

		const Menu_State getMenuState()const;

	private:
		void initButtons();
		void setButtonProperty();
		Button* m_PlayButton;
		Button* m_QuitButton;
		SDL_Renderer* m_Renderer;
		SDL_Event m_Event;
	};
};