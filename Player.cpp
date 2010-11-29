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

Player::Player(Level& level) : xVel(0), yVel(0), level(level)
{
	box.x = 200;
	box.y = 200;
	box.w = PLAYER_WIDTH;
	box.h = PLAYER_HEIGTH;
}

void Player::handle_events_state()
{
	xVel = 0; yVel = 0;

	Uint8 *keystates = SDL_GetKeyState( NULL );
	if(keystates[SDLK_UP] )
	{
		yVel = -2;
	}
	if(keystates[SDLK_DOWN] )
	{
		yVel = 2;
	}
	if(keystates[SDLK_LEFT] )
	{
		xVel = -2;
	}
	if(keystates[SDLK_RIGHT] )
	{
		xVel = 2;
	}
}

void Player::move()
{
	std::vector<std::string> colliding_objects_type;

	box.x += xVel;
	box.y += yVel;

	colliding_objects_type = level.check_collisions(this);

	if( Gamerules::can_move("Player", colliding_objects_type ) == false )
	{
		box.x -= xVel;
		box.y -= yVel;
	}
}

bool Player::show( SDL_Surface* screen)
{
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
 /* Return the player SDL_Rectangle object */

	return &box;
}

std::string Player::get_type()
{
	return "Player";
}

Player::~Player() {

}
