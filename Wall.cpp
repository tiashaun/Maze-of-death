/*
 * Wall.cpp
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#include "Wall.h"

static SDL_Surface *wall_image = NULL;

const int Wall_WIDTH = 10;
const int Wall_Unreactive_HEIGTH = 10;

Wall::Wall(	Level& start_level, int x, int y) : level(start_level)
{
	is_moveable = false;
	box.x = x;
	box.y = y;
	box.w = Wall_WIDTH;
	box.h = Wall_Unreactive_HEIGTH;
	type = "Wall";
}

void Wall::move(){

}

void Wall::update(){

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
