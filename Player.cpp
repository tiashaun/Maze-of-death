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

const int PLAYER_WIDTH = 40;
const int PLAYER_HEIGTH = 40;

Player::Player()
{
	box.x = 200;
	box.y = 200;
	box.w = PLAYER_WIDTH;
	box.h = PLAYER_HEIGTH;

	xVel = 2;
	yVel = 2;
}


void Player::handle_events_state()
{
	Uint8 *keystates = SDL_GetKeyState( NULL );
	if(keystates[SDLK_UP] )
	{
		box.y -= yVel;
	}
	if(keystates[SDLK_DOWN] )
	{
		box.y += yVel;
	}
	if(keystates[SDLK_LEFT] )
	{
		box.x -= xVel;
	}
	if(keystates[SDLK_RIGHT] )
	{
		box.x += xVel;
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

Player::~Player() {

}
