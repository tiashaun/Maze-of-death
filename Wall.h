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
	Wall(Level& level, Gamerules& gamerules, int x, int y);
	virtual ~Wall();
	void show(SDL_Surface* screen);
	void update();
	bool check_for_player();
	void move();
	SDL_Rect* get_rect();
private:
	std::string get_type();
	int xCordinate;
	int yCordinate;
	SDL_Rect box;
	bool init_image();
	Level& level;
	Gamerules& gamerules;
};

#endif /* WALL_H_ */
