/*
 * Player.cpp
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#include "Player.h"
#include "Game.h"


#include <SDL/SDL.h>

#include <iostream>
#include <vector>

const int PLAYER_WIDTH = 40;
const int PLAYER_HEIGTH = 40;

Player::Player(Level& level, Gamerules& gamerules) : Moving_Sprite(level), gamerules(gamerules)
{
	set_xVelocity(0);
	set_yVelocity(0);
	set_is_object_movable(true);
	set_type("Player");			// Type name used to identify this player.
	box.x = 200;				// Player's SDL_Rect, x-coordinate
	box.y = 200;				// Player's SDL_Rect, y-coordinate
	box.w = PLAYER_WIDTH;		// Player's SDL_Rect, width
	box.h = PLAYER_HEIGTH;		// Player's SDL_Rect, height

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
	colliding_objects_type = get_level().check_collisions(this);

	// Check if the enemy collide with something it can't collide with.
	if( get_level().get_gamerules().can_move(get_type(), colliding_objects_type ) == false )
	{
		// If so back the player away with an equal distance of its velocity value.
		box.x -= get_xVelocity();
		box.y -= get_yVelocity();
	}
}


void Player::show( SDL_Surface* screen)
{
	/*
	 * Draw player object on screen
	 * @param screen
	 */

	write_to_screen(screen, "Images/Player.jpg", box.x, box.y);
}



Player::~Player() {

}
