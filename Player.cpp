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

Player::Player()
{
	box.x = 200;
	box.y = 200;
	box.w = 50;
	box.h = 50;
}


void Player::handle_events_state()
{
	Uint8 *keystates = SDL_GetKeyState( NULL );
	if(keystates[SDLK_UP] )
	{
		box.y -= 20;
	}
	if(keystates[SDLK_DOWN] )
	{
		box.y += 20;
	}
	if(keystates[SDLK_LEFT] )
	{
		box.x -= 20;
	}
	if(keystates[SDLK_RIGHT] )
	{
		box.x += 20;
	}
}

void Player::handle_events_press(SDL_Event &event)
{
	//If a key was pressed
	if( event.type == SDL_KEYDOWN )
	{
		switch( event.key.keysym.sym )
		{
		case SDLK_UP:
			box.y -= 20;
			break;
		case SDLK_DOWN:
			box.y += 20;
			break;
		case SDLK_LEFT:
			box.x -= 20;
			break;
		case SDLK_RIGHT:
			box.x += 20;
			break;
		}

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
