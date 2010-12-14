/*
 * Moving_Sprite.h
 *
 *  Created on: Nov 30, 2010
 *      Author: matol004
 */

#ifndef MOVING_SPRITE_H_
#define MOVING_SPRITE_H_
#include "Sprite.h"
#include <SDL/SDL.h>

struct Direction {
	float x, y;
};

struct Velocity {
	int x, y;
};

class Moving_Sprite : public Sprite {
	/**
	 *  This object holds all the functions and variables for the Moving_Sprite object.
	 *  Moving_Sprite provides functionality to move and calculate distance and velocity.
	 */
public:
	Moving_Sprite(Level& level, float speed);
	virtual ~Moving_Sprite();
	virtual void update() = 0;
	virtual void move();
	SDL_Rect* get_rect();
	float get_speed();

protected:
	Velocity calculate_velocity(int object_x_coordinate, int object_y_coordinate,
			int target_x_coordinate, int target_y_coordinate, int move_speed);
	int get_xVelocity();
	int get_yVelocity();
	void set_xVelocity(int x_new_vel);
	void set_yVelocity(int y_new_vel);
	SDL_Rect box;
private:
	const float speed; 					// Number of pixels to move per object update
	int x_velocity;
	int y_velocity;
};

#endif /* MOVING_SPRITE_H_ */
