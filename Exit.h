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
	Exit(Level& level, Gamerules& gamerules, int x, int y);
	virtual ~Exit();
	void show(SDL_Surface* destination);
	void update();
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

#endif /* Exit_H_ */
