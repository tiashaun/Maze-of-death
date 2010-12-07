/*
 * Game.h
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#ifndef GAME_H_
#define GAME_H_

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
	SDL_Event event;
	SDL_Surface *screen;
	TTF_Font* font;
	std::vector<Sprite*> fictious_level(Level *first_level, Gamerules& game_rules_pointer);
};

#endif /* GAME_H_ */
