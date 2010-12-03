/*
 * Wall.cpp
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#include "Exit.h"

static SDL_Surface *Exit_image = NULL;

const int Exit_WIDTH = 10;
const int Exit_Unreactive_HEIGTH = 10;

Exit::Exit(	Level& level, Gamerules& gamerules, int x, int y) : Sprite(level), gamerules(gamerules)
{
	set_is_object_movable(false);
	set_type("Exit");
	box.x = x;
	box.y = y;
	box.w = Exit_WIDTH;
	box.h = Exit_Unreactive_HEIGTH;

}

void Exit::move(){

}

void Exit::update(){

}

bool Exit::init_image()
{
	if(Exit_image == NULL )
	{
			Exit_image = load_image( "Images/Player.jpg" );
			if(Exit_image == NULL )
			{
				return false;
			}
	}
	return true;
}

void Exit::show(SDL_Surface* destination)
{
	init_image();
	apply_surface(box.x, box.y, Exit_image, destination);
}

SDL_Rect* Exit::get_rect()
{
	return &box;
}

Exit::~Exit() {

}
