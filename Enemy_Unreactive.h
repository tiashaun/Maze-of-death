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
public:
	Enemy_Unreactive(Level& level, Gamerules& gamerules, int xCord,int yCord, float speed, std::vector<Node*> *nodes);
	virtual ~Enemy_Unreactive();
	void show(SDL_Surface* screen);
	void update();
private:
	Gamerules& gamerules;
};

#endif /* ENEMY_UNREACTIVE_H_ */
