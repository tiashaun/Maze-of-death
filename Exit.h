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
	/**
	 *  This object holds all the functions and variables for the Exit object.
	 *  The Exit object is used to win the map.
	 */
public:
	Exit(Level& level, int x_start_coordinate, int y_start_coordinate);
	virtual ~Exit();
	void show(SDL_Surface* screen);
	void update();
	void move();
	SDL_Rect* get_rect();
private:
	Gamerules& gamerules;			//!< The gamerules object that applies to the level
	SDL_Rect box;					//!< The SDL_Rect box that repesent the object.
	SDL_Surface* image;				//!< Image of the Enemy_Reactive
};

#endif /* Exit_H_ */
