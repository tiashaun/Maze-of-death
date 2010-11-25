/*
 * Level.h
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#ifndef LEVEL_H_
#define LEVEL_H_

#include "Sprite.h"

#include <vector>

class Level {
public:
	Level(SDL_Surface* destination);
	virtual ~Level();
	void fictious_level();
	void draw_game_objects();
private:
	std::vector<Sprite*> game_objects;
	SDL_Surface* destination;
};

#endif /* LEVEL_H_ */
