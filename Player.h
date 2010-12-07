/*
 * Player.h
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "SDL/SDL.h"
#include "Moving_Sprite.h"
#include "Gamerules.h"

#include "Level.h"

#include <string>

class Player : public Moving_Sprite {

public:
	Player(Level& level, int x_start_coordinate, int y_start_coordinate, float speed);
	virtual ~Player();
	void handle_events_state();
	void show(SDL_Surface* screen);
	void update();
	//SDL_Rect* get_rect();
private:
	Gamerules& gamerules;
	int x_velocity;			// The players x velocity.
	int y_velocity;			// The players y velocity.
};

#endif /* PLAYER_H_ */
