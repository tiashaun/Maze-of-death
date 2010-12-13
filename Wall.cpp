/*
 * Wall.cpp
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#include "Wall.h"

const int Wall_WIDTH = 10;
const int Wall_HEIGTH = 10;

Wall::Wall(	Level& level, int x, int y) : Sprite(level), gamerules(get_level().get_gamerules()) {
	set_is_object_movable(false);
	set_type("Wall");
	box.x = x;
	box.y = y;
	box.w = Wall_WIDTH;
	box.h = Wall_HEIGTH;
	image = NULL;
}

void Wall::show(SDL_Surface* screen) {
	if( image  == NULL )
	{
		image = load_image( "Images/Wall.jpg" );
	}

	apply_surface( box.x, box.y, image, screen );
}

SDL_Rect* Wall::get_rect() {
	return &box;
}


Wall::~Wall() {
	delete image;
	image = NULL;
}
