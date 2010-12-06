/*
 * Moving_Sprite.cpp
 *
 *  Created on: Nov 30, 2010
 *      Author: matol004
 */

#include "Moving_Sprite.h"
#include <cmath>

Moving_Sprite::Moving_Sprite(Level& level, float speed) : Sprite(level), speed(speed){
	// TODO Auto-generated constructor stub

}

Moving_Sprite::~Moving_Sprite() {
}

int Moving_Sprite::get_xVelocity() {
	return x_velocity;
}

int Moving_Sprite::get_yVelocity() {
	return y_velocity;
}

void Moving_Sprite::set_xVelocity(int x_new_vel) {
	x_velocity = x_new_vel;
}

void Moving_Sprite::set_yVelocity(int y_new_vel) {
	y_velocity = y_new_vel;
}

float Moving_Sprite::get_speed(){
	return speed;
}

Velocity Moving_Sprite::calculate_velocity(int object_x_coordinate, int object_y_coordinate,
		int target_x_coordinate, int target_y_coordinate, int const move_speed) {
	/**
	 * Calulate which direction the object should move, to end up at target position
	 *
	 * http://stackoverflow.com/questions/2625021/game-enemy-move-towards-player/2625107#2625107
	 */

	Direction direction;

	//Calculate hypotenuse
	direction.x = target_x_coordinate - object_x_coordinate;
	direction.y = target_y_coordinate - object_y_coordinate;
	float hypotenuse = sqrt(direction.x * direction.x + direction.y * direction.y);

	direction.x /= hypotenuse;
	direction.y /= hypotenuse;

	//Calculate velocity, since it's for both x and y -> direction
	Velocity vel;
	vel.x = round(direction.x) * move_speed;
	vel.y = round(direction.y) * move_speed;

	return vel;
}

void Moving_Sprite::move() {
	/*
	 * Move player to the new position
	 */
	box.x += get_xVelocity();
	box.y += get_yVelocity();
}


SDL_Rect* Moving_Sprite::get_rect() {
 /**
  * Return pointer to the objects SDL_Rectangle
  */
	return &box;
}
