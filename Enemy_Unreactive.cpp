/*
 * Player.cpp
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#include "Enemy_Unreactive.h"
#include "Game.h"


#include <iostream>
#include <vector>

const int Enemy_Reactive_WIDTH = 40;	// Enemy's SDL_rectangle width
const int Enemy_Reactive_HEIGTH = 40;	// Enemy's SDL_rectangle heigth

Enemy_Unreactive::Enemy_Unreactive(Level& level ,int x_start_coordinate,
		int y_start_coordinate, float speed, std::vector<Node*> *nodes) : Enemy(level, speed, nodes), gamerules(get_level().get_gamerules()) {
	set_is_object_movable(true);
	set_type("Enemy_Unreactive");			// Type name used to identify this enemy.
	box.x = x_start_coordinate;			// Enemy's SDL_Rect, x-coordinate
	box.y = y_start_coordinate;			// Enemy's SDL_Rect, y-coordinate
	box.w = Enemy_Reactive_WIDTH;		// Enemy's SDL_Rect, width
	box.h = Enemy_Reactive_HEIGTH;		// Enemy's SDL_Rect, height

}


void Enemy_Unreactive::update() {
	/*
	*  Move player to new position and check if it's ok to be there
	*  if not, move him back to old position
	*/
	//std::cerr << "eneym";

	move_to_target_node();
	std::cerr << "lala";
	move();

	std::vector<std::string> colliding_objects_type; //Store type of colliding objects
	colliding_objects_type = get_level().check_collisions(this);

	// Check if the enemy collide with something it can't collide with.
	if( !colliding_objects_type.empty()
		&&	get_level().get_gamerules().can_move(get_type(), colliding_objects_type ) == false)
	{
		// If it does, take him back to last position
		box.x -= get_xVelocity();
		box.y -= get_yVelocity();
	}
	else
	{
		// He dosn't collide with anything and dosn't need to be moved back.
	}

}

void Enemy_Unreactive::show( SDL_Surface* screen) {
	/*
	 * Draw Enemy_Unreactive object on screen
	 * @param screen
	 */

	write_to_screen(screen, "Images/Player.jpg", box.x, box.y);
}

Enemy_Unreactive::~Enemy_Unreactive() {

}
