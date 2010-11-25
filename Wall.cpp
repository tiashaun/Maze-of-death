/*
 * Wall.cpp
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#include "Wall.h"

static SDL_Surface *wall_image = NULL;

Wall::Wall(int x, int y) : xCordinate(x), yCordinate(y)
{

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

void Wall::show(SDL_Surface* destination)
{
	init_image();
	apply_surface(xCordinate, yCordinate, wall_image, destination);
}

Wall::~Wall() {

}
