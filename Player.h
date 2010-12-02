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
	Player(Level& level, Gamerules& gamerules);
	virtual ~Player();
	void handle_events_state();
	void show(SDL_Surface* screen);
	void update();
	void move();
	//SDL_Rect* get_rect();
private:
	std::string get_type();
	int x_velocity;			// The players x velocity.
	int y_velocity;			// The players y velocity.
	Level& level;			// The level this player is on.
	Gamerules& gamerules;	// The gamerules which this player obides to.
};

#endif /* PLAYER_H_ */
