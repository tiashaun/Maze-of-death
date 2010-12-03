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

Enemy_Unreactive::Enemy_Unreactive(Level& level, Gamerules&  gamerules,int x_start_coordinate,
		int y_start_coordinate, int x_start_velocity, int y_start_velocity, std::vector<int> start_xNodes,
		std::vector<int> start_yNodes) : level(level), gamerules(gamerules)
{
	is_moveable = true;
	set_xVelocity( x_start_velocity);	// Which velocity the enemy is moving on the x-axis.
	set_yVelocity( y_start_velocity);	// Which velocity the enemy is moving on the y-axis.
	box.x = x_start_coordinate;			// Enemy's SDL_Rect, x-coordinate
	box.y = y_start_coordinate;			// Enemy's SDL_Rect, y-coordinate
	box.w = Enemy_Reactive_WIDTH;		// Enemy's SDL_Rect, width
	box.h = Enemy_Reactive_HEIGTH;		// Enemy's SDL_Rect, height
	xNodes = start_xNodes;				// Points to the nodes x-value that the enemy should start to head towards.
	yNodes = start_yNodes;				// Points to the nodes y-value that the enemy should start to head towards.
	node_counter=0;
	type = "Enemy_Unreactive";			// Type name used to identify this enemy.
}


void Enemy_Unreactive::move()
{
	/*
	 * Move player to the new position
	 */
	box.x += get_xVelocity();
	box.y += get_yVelocity();

}

void Enemy_Unreactive::update()
{
	/*
	*  Move player to new position and check if it's ok to be there
	*  if not, move him back to old position
	*/
	//std::cerr << "eneym";
	move();

	std::vector<std::string> colliding_objects_type; //Store type of colliding objects
	colliding_objects_type = level.check_collisions(this);

	// Check if the enemy collide with something it can't collide with.
	if( gamerules.can_move(type, colliding_objects_type ) == false )
	{
		// If so back the player away with an equal distance of its velocity value.
		box.x -= get_xVelocity();
		box.y -= get_yVelocity();
		// Reverse the speed of the enemy so it goes back along its path.
		int temp_xVelocity = (-1)*get_xVelocity();
		set_xVelocity(temp_xVelocity);
		int temp_yVelocity = (-1)*get_yVelocity();
		set_yVelocity(temp_yVelocity);
	}
//	else if(0 < get_xVelocity() && box.x > xNodex[node_counter])
//	{
//
//	}
//
//	node_counter+=1;
}

void Enemy_Unreactive::show( SDL_Surface* screen)
{
	/*
	 * Draw Enemy_Unreactive object on screen
	 * @param screen
	 */

	write_to_screen(screen, "Images/Player.jpg", box.x, box.y);
}

std::string Enemy_Unreactive::get_type()
{
	return "Enemy_Unreactive";
}

Enemy_Unreactive::~Enemy_Unreactive() {

}
