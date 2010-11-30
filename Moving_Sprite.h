/*
 * Moving_Sprite.h
 *
 *  Created on: Nov 30, 2010
 *      Author: matol004
 */

#ifndef MOVING_SPRITE_H_
#define MOVING_SPRITE_H_
#include "Sprite.h"

class Moving_Sprite : public Sprite {
public:
	Moving_Sprite();
	virtual ~Moving_Sprite();

	int get_xVelocity();
	int get_yVelocity();

	void set_xVelocity(int x_new_vel);
	void set_yVelocity(int y_new_vel);
	virtual void move() = 0;
	virtual void update() = 0;

private:
	int x_velocity;
	int y_velocity;
};

#endif /* MOVING_SPRITE_H_ */
