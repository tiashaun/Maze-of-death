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

public:
	Game();
	virtual ~Game();
	int run();
	bool init();
	void clean_up();
private:
	void handle_menu_events(Level& level, Menu& menu, Timer& timer, bool& quit);
	SDL_Event event;
	SDL_Surface *screen;
	TTF_Font* font;
	bool quit;
};

#endif /* GAME_H_ */
