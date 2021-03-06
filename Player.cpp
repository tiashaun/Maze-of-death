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

Player::Player(Level& level, int x_start_coordinate, int y_start_coordinate, float speed)
	: Moving_Sprite(level, speed), gamerules(get_level().get_gamerules()) {
	/**
	 * Constructor for Player
	 * @param level The level object that the object will belong to
	 * @param x_start_coordinate The x position the object should start on
	 * @param y_start_coordinate The y position the object should start on
	 * @param speed The speed that the object will have on the level, provided as a float.
	 * @return A Player object
	 */
	set_xVelocity(0);
	set_yVelocity(0);
	set_is_object_movable(true);
	set_type("Player");				// Type name used to identify this player.
	box.x = x_start_coordinate;		// Enemy's SDL_Rect, x-coordinate
	box.y = y_start_coordinate;		// Enemy's SDL_Rect, y-coordinate
	box.w = PLAYER_WIDTH;			// Player's SDL_Rect, width
	box.h = PLAYER_HEIGTH;			// Player's SDL_Rect, height
	image = NULL;
}

void Player::handle_events_state() {
	/**
	 * Handle keyboard events and make corresponding action on the player
	 */

	set_xVelocity(0); //X-axis velocity
	set_yVelocity(0); //Y-axis velocity

	Uint8 *keystates = SDL_GetKeyState( NULL );
	if(keystates[SDLK_UP] )
	{
		set_yVelocity(-this->get_speed());
	}
	if(keystates[SDLK_DOWN] )
	{
		set_yVelocity(get_speed());
	}
	if(keystates[SDLK_LEFT] )
	{
		set_xVelocity(-get_speed());
	}
	if(keystates[SDLK_RIGHT] )
	{
		set_xVelocity(get_speed());
	}
}

void Player::update() {
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


void Player::show( SDL_Surface* screen) {
	/*
	 * Draw player object on screen
	 * @param screen
	 */

	if( image  == NULL )
	{
		image = load_image( "Images/mainchar.bmp" );
	}

	apply_surface( box.x, box.y, image, screen );
}



Player::~Player() {
	/**
	 * Frees the image memory.
	 */
	// Check if the object has an image
	if(image != NULL)
	{
		// if it has free the memory space.
		SDL_FreeSurface(image);
	}
}
