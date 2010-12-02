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

const int Enemy_Unreactive_WIDTH = 40;
const int Enemy_Unreactive_HEIGTH = 40;

Enemy_Unreactive::Enemy_Unreactive(Level& level, Gamerules&  gamerules,int x_start_coordinate,int y_start_coordinate, int x_start_velocity, int y_start_velocity, std::vector<int> start_xNodes, std::vector<int> start_yNodes)
	: level(level), gamerules(gamerules)
{
	is_moveable = true;
	set_xVelocity( x_start_velocity);
	set_yVelocity( y_start_velocity);
	box.x = x_start_coordinate;
	box.y = y_start_coordinate;
	box.w = Enemy_Unreactive_WIDTH;
	box.h = Enemy_Unreactive_HEIGTH;
	xNodes = start_xNodes;
	yNodes = start_yNodes;
	node_counter=0;
	type = "Enemy_Unreactive";
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
	* Move player to new position and check if it's ok to be there
	* if not, move him back to old position
	*/
	//std::cerr << "eneym";
	move();

	std::vector<std::string> colliding_objects_type; //Store type of colliding objects
	colliding_objects_type = level.check_collisions(this);

	//If the player collides with objects which is not ok to collide with,
	//take him back to the old position
	if( gamerules.can_move(type, colliding_objects_type ) == false )
	{
		box.x -= get_xVelocity();
		box.y -= get_yVelocity();
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
