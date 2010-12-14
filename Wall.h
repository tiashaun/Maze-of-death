/*
 * Wall.h
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#ifndef WALL_H_
#define WALL_H_

#include "Sprite.h"
#include <SDL/SDL.h>
#include "Level.h"
#include "Gamerules.h"

#include <string>

class Wall : public Sprite {
public:
	Wall(Level& level, int x_start_coordinate, int y_start_coordinate);
	virtual ~Wall();
	void show(SDL_Surface* screen);
	bool check_for_player();
	SDL_Rect* get_rect();
private:
	Gamerules& gamerules;
	SDL_Rect box;
	SDL_Surface* image;
};

#endif /* WALL_H_ */
