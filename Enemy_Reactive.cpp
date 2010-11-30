/*
 * Player.cpp
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#include "Enemy_Reactive.h"
#include "Game.h"
#include "Gamerules.h"



#include <iostream>
#include <vector>

const int Enemy_Reactive_WIDTH = 40;
const int Enemy_Reactive_HEIGTH = 40;

Enemy_Reactive::Enemy_Reactive(Level& level,int xCord,int yCord) : xVel(0), yVel(0), level(level)
{
	is_moveable = false;
	box.x = xCord;
	box.y = yCord;
	box.w = Enemy_Reactive_WIDTH;
	box.h = Enemy_Reactive_HEIGTH;
}


void Enemy_Reactive::move()
{
	/*
	 * Check if the Enemy_Reactive can move in the desired direction
	 * and if ok move there
	 */

	//Move Enemy_Reactive to the new position
	box.x += xVel;
	box.y += yVel;

	std::vector<std::string> colliding_objects_type; //Store type of colliding objects
	colliding_objects_type = level.check_collisions(this);

	//If the Enemy_Reactive collides with objects which is not ok to collide with,
	//take him back to the old position
	if( Gamerules::can_move("Enemy_Reactive", colliding_objects_type ) == false )
	{
		box.x -= xVel;
		box.y -= yVel;
	}
}

bool Enemy_Reactive::show( SDL_Surface* screen)
{
	/*
	 * Draw Enemy_Reactive object on screen
	 * @param screen
	 */

	SDL_Surface *Enemy_Reactive_image = NULL;

	Enemy_Reactive_image = load_image( "Images/Enemy_Reactive.jpg" );

	if( Enemy_Reactive_image == NULL )
	{
		return false;
	}

	apply_surface( box.x, box.y, Enemy_Reactive_image, screen); //Draw on screen
	return true;
}

SDL_Rect* Enemy_Reactive::get_rect()
{
 /**
  * Return the Enemy_Reactive objects SDL_Rectangle
  */

	return &box;
}

std::string Enemy_Reactive::get_type()
{
	return "Enemy_Reactive";
}

Enemy_Reactive::~Enemy_Reactive() {

}
