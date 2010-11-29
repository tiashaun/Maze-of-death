/*
 * Player.h
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "SDL/SDL.h"
#include "Sprite.h"

#include "Level.h"

#include <string>

class Player : public Sprite {

public:
	Player(Level& level);
	virtual ~Player();
	void handle_events_state();
	bool show(SDL_Surface* screen);
	void move();
	SDL_Rect* get_rect();
private:
	std::string get_type();
	SDL_Rect box;
	int xVel;
	int yVel;
	Level& level;
};

#endif /* PLAYER_H_ */
