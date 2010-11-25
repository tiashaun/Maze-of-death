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

class Wall : public Sprite {
public:
	Wall(int x, int y);
	virtual ~Wall();
	bool show(SDL_Surface* destination);
protected:
	int xCordinate;
	int yCordinate;
private:
	SDL_Rect box;
	bool init_image();
};

#endif /* WALL_H_ */
