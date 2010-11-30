/*
 * Enemy_reactive.h
 *
 *  Created on: Nov 30, 2010
 *      Author: matol004
 */

#ifndef ENEMY_REACTIVE_H_
#define ENEMY_REACTIVE_H_
#include "Enemy.h"
#include "Level.h"

class Enemy_Reactive : public Enemy {
public:
	Enemy_Reactive(Level& level,int xCord,int yCord);
	virtual ~Enemy_Reactive();
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

#endif /* ENEMY_REACTIVE_H_ */
