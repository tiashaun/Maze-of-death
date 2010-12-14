/*
 * Game.h
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#ifndef GAME_H_
#define GAME_H_

class Menu;
class Timer;
class Level;

#include <string>
#include <vector>
#include <SDL/SDL.h>
#include "Gamerules.h"
#include "SDL/SDL_ttf.h"
#include "Sprite.h"


class Game {
	/**
	 *  This object holds all the functions and variables for the game object.
	 *  The game objects holds all functions to run the game.
	 */

public:
	Game();
	virtual ~Game();
	int run();
private:
	void clean_up();
	bool init();
	void return_to_menu(Gamerules& game_rules, Menu& menu, Timer& timer);
	void handle_menu_events(Level& level, Menu& menu, Timer& timer, bool& quit);
	SDL_Event event;		//<! The event handler for the game
	SDL_Surface *screen;	//<! The screen object for the game
	TTF_Font* font;			//<! The font for the game
	bool quit;				//<! Bool used to chek if the game should exit
};

#endif /* GAME_H_ */
