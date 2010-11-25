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

class Player : public Sprite {

public:
	Player();
	virtual ~Player();
	void handle_events_state();
	bool show(SDL_Surface* screen);

private:
	SDL_Rect box;
	int xVel;
	int yVel;
};

#endif /* PLAYER_H_ */
