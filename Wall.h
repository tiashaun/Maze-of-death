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
	void show(SDL_Surface* destination);
protected:
	int xCordinate;
	int yCordinate;
private:
	bool init_image();
};

#endif /* WALL_H_ */
