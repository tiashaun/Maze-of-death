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

	int get_xVel();
	int get_yVel();

	void set_xVel(int x_new_vel);
	void set_yVel(int y_new_vel);

private:
	int xVel;
	int yVel;
};

#endif /* MOVING_SPRITE_H_ */
