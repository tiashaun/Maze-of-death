/*
 * Player.cpp
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#include "Player.h"
#include "Game.h"
#include "Gamerules.h"

#include <SDL/SDL.h>

#include <iostream>
#include <vector>

const int PLAYER_WIDTH = 40;
const int PLAYER_HEIGTH = 40;

Player::Player(Level& level) : x_velocity(0), y_velocity(0), level(level)
{
	is_moveable = true;
	box.x = 200;
	box.y = 200;
	box.w = PLAYER_WIDTH;
	box.h = PLAYER_HEIGTH;
	type = "Player";
}

void Player::handle_events_state()
{
	/*
	 * Handle keyboard events and make corresponding action on the player
	 */

	set_xVelocity(0); //X-axis velocity
	set_yVelocity(0); //Y-axis velocity

	Uint8 *keystates = SDL_GetKeyState( NULL );
	if(keystates[SDLK_UP] )
	{
		set_yVelocity(-2);
	}
	if(keystates[SDLK_DOWN] )
	{
		set_yVelocity(2);
	}
	if(keystates[SDLK_LEFT] )
	{
		set_xVelocity(-2);
	}
	if(keystates[SDLK_RIGHT] )
	{
		set_xVelocity(2);
	}
}


void Player::move()
{
	/*
	 * Move player to the new position
	 */
	box.x += get_xVelocity();
	box.y += get_yVelocity();
}

void Player::update()
{
	/*
	* Move player to new position and check if it's ok to be there
	* if not, move him back to old position
	*/

	move();

	std::vector<std::string> colliding_objects_type; //Store type of colliding objects
	colliding_objects_type = level.check_collisions(this);

	//If the player collides with objects which is not ok to collide with,
	//take him back to the old position
	if( Gamerules::can_move("Player", colliding_objects_type ) == false )
	{
		box.x -= get_xVelocity();
		box.y -= get_yVelocity();
	}
}

bool Player::show( SDL_Surface* screen)
{
	/*
	 * Draw player object on screen
	 * @param screen
	 */

	SDL_Surface *player_image = NULL;

	player_image = load_image( "Images/Player.jpg" );

	if( player_image == NULL )
	{
		return false;
	}

	apply_surface( box.x, box.y, player_image, screen); //Draw on screen
	return true;
}

SDL_Rect* Player::get_rect()
{
 /**
  * Return the player objects SDL_Rectangle
  */
	return &box;
}

std::string Player::get_type()
{
	return "Player";
}

Player::~Player() {

}
