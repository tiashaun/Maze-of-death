/*
 * Wall.cpp
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#include "Wall.h"

static SDL_Surface *wall_image = NULL;

Wall::Wall(int x, int y)
{
	is_moveable = false;
	box.x = x;
	box.y = y;
	box.w = 10;
	box.h = 10;
}

bool Wall::init_image()
{
	if(wall_image == NULL )
	{
			wall_image = load_image( "Images/Wall.jpg" );
			if(wall_image == NULL )
			{
				return false;
			}
	}
	return true;
}

bool Wall::show(SDL_Surface* destination)
{
	init_image();
	apply_surface(box.x, box.y, wall_image, destination);
	return true;
}

SDL_Rect* Wall::get_rect()
{
	return &box;
}

std::string Wall::get_type()
{
	return "Wall";
}

Wall::~Wall() {

}
