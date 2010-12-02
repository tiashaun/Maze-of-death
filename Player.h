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
	int x_velocity;
	int y_velocity;
	Level& level;
	Gamerules& gamerules;
};

#endif /* PLAYER_H_ */
