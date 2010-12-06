/*
 * Game.h
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#ifndef GAME_H_
#define GAME_H_

#include <string>
#include <SDL/SDL.h>
#include "SDL/SDL_ttf.h"

class Game {

public:
	Game();
	virtual ~Game();
	int run();
	bool init();
	void clean_up();
private:
	SDL_Event event;
	SDL_Surface *screen;
	TTF_Font* font;
};

#endif /* GAME_H_ */
