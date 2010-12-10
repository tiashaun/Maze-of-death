/*
 * Wall.h
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#ifndef EXIT_H_
#define EXIT_H_

#include "Sprite.h"
#include <SDL/SDL.h>
#include "Level.h"
#include "Gamerules.h"
#include <string>



class Exit : public Sprite {
public:
	Exit(Level& level, int x, int y);
	virtual ~Exit();
	void show(SDL_Surface* screen);
	void update();
	void move();
	SDL_Rect* get_rect();
private:
	Gamerules& gamerules;
	SDL_Rect box;
	SDL_Surface* image;
};

#endif /* Exit_H_ */
