/*
 * Player.cpp
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#include "Enemy_Unreactive.h"
#include "Game.h"
#include "Gamerules.h"



#include <iostream>
#include <vector>

const int Enemy_Unreactive_WIDTH = 40;
const int Enemy_Unreactive_HEIGTH = 40;

Enemy_Unreactive::Enemy_Unreactive(Level& level,int xCord,int yCord) : xVel(0), yVel(0), level(level)
{
	is_static = false;
	box.x = xCord;
	box.y = yCord;
	box.w = Enemy_Unreactive_WIDTH;
	box.h = Enemy_Unreactive_HEIGTH;
}


void Enemy_Unreactive::move()
{
	/*
	 * Check if the Enemy_Unreactive can move in the desired direction
	 * and if ok move there
	 */

	//Move Enemy_Unreactive to the new position
	box.x += xVel;
	box.y += yVel;

	std::vector<std::string> colliding_objects_type; //Store type of colliding objects
	colliding_objects_type = level.check_collisions(this);

	//If the Enemy_Unreactive collides with objects which is not ok to collide with,
	//take him back to the old position
	if( Gamerules::can_move("Enemy_Unreactive", colliding_objects_type ) == false )
	{
		box.x -= xVel;
		box.y -= yVel;
	}
}

bool Enemy_Unreactive::show( SDL_Surface* screen)
{
	/*
	 * Draw Enemy_Unreactive object on screen
	 * @param screen
	 */

	SDL_Surface *Enemy_Unreactive_image = NULL;

	Enemy_Unreactive_image = load_image( "Images/Enemy_Unreactive.jpg" );

	if( Enemy_Unreactive_image == NULL )
	{
		return false;
	}

	apply_surface( box.x, box.y, Enemy_Unreactive_image, screen); //Draw on screen
	return true;
}

SDL_Rect* Enemy_Unreactive::get_rect()
{
 /**
  * Return the Enemy_Unreactive objects SDL_Rectangle
  */

	return &box;
}

std::string Enemy_Unreactive::get_type()
{
	return "Enemy_Unreactive";
}

Enemy_Unreactive::~Enemy_Unreactive() {

}
