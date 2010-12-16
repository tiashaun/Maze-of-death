/*
 * Moving_Sprite.cpp
 *
 *  Created on: Nov 30, 2010
 *      Author: matol004
 */

#include "Moving_Sprite.h"
#include <cmath>

Moving_Sprite::Moving_Sprite(Level& level, float speed) : Sprite(level), speed(speed){
	/**
	 * Constructor for Moving_Sprite. Pass level to Sprite constructor.
	 * @param level The level object that the object will belong to
	 * @param speed The speed that the object will have on the level, provided as a float.
	 * @warning Is an abstract class should not be instantiated.
	 * @return A Moving_Sprite object
	 */

}

Moving_Sprite::~Moving_Sprite() {
	/**
	 * Destructor for Moving_Sprite
	 */
}

int Moving_Sprite::get_xVelocity() {
	/**
	 * Returns the xVelocity of the object.
	 * @return Return the xVeclocity as a int.
	 */
	return x_velocity;
}

int Moving_Sprite::get_yVelocity() {
	/**
	 * Returns the yVelocity of the object.
	 * @return Return the yVeclocity as a int.
	 */
	return y_velocity;
}

void Moving_Sprite::set_xVelocity(int x_new_vel) {
	/**
	 * Sets the xVelocity of the object.
	 * @param x_new_vel The new value for the objects xVelocity
	 */
	x_velocity = x_new_vel;
}

void Moving_Sprite::set_yVelocity(int y_new_vel) {
	/**
	 * Sets the yVelocity of the object.
	 * @param y_new_vel The new value for the objects yVelocity
	 */
	y_velocity = y_new_vel;
}

float Moving_Sprite::get_speed(){
	/**
	 * Returns the speed of the object.
	 * @return Return the speed as a float.
	 */
	return speed;
}

Velocity Moving_Sprite::calculate_velocity(int object_x_coordinate, int object_y_coordinate,
		int target_x_coordinate, int target_y_coordinate, int const move_speed) {
	/**
	 * Calulate which direction the object should move, to end up at target position
	 * http://stackoverflow.com/questions/2625021/game-enemy-move-towards-player/2625107#2625107
	 * @param object_x_coordinate	The x coordinate of the first object
	 * @param object_y_coordinate	The y coordinate of the first object
	 * @param target_x_coordinate	The x coordinate of the second object
	 * @param target_y_coordinate	The y coordinate of the second object
	 * @param move_speed			The move speed of the first object
	 * @return Returns the Velocity needed in x and y to reach the target coordinates if it stands still. Returns as a Velocity object.
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
  * @return Return pointer to the objects SDL_Rectangle
  */
	return &box;
}
