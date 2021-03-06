/*
 * Enemy_Unreactive.h
 *
 *  Created on: Nov 30, 2010
 *      Author: matol004
 */

#ifndef ENEMY_UNREACTIVE_H_
#define ENEMY_UNREACTIVE_H_
#include "Enemy.h"
#include "Level.h"
#include "Gamerules.h"

class Enemy_Unreactive : public Enemy {
	/**
	 *  This object holds all the functions and variables for the Enemy_Unreactive object.
	 */
public:
	Enemy_Unreactive(Level& level, int x_start_coordinate, int y_start_coordinate, float speed, std::vector<Node*> *nodes);
	virtual ~Enemy_Unreactive();
	void show(SDL_Surface* screen);
	void update();
private:
	Gamerules& gamerules;				//!< The gamerules object that applies to the level
	SDL_Surface* image;					//!< Image of the Enemy_Reactive
};

#endif /* ENEMY_UNREACTIVE_H_ */
