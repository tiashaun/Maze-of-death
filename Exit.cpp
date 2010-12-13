/*
 * Wall.cpp
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#include "Exit.h"
#include <iostream>

const int Exit_WIDTH = 40;
const int Exit_HEIGTH = 40;

Exit::Exit(	Level& level, int x, int y) : Sprite(level), gamerules(get_level().get_gamerules()) {
	set_is_object_movable(false);
	set_type("Exit");
	box.x = x;
	box.y = y;
	box.w = Exit_WIDTH;
	box.h = Exit_HEIGTH;
	image = NULL;
}

void Exit::move() {

}

void Exit::update() {

}

void Exit::show(SDL_Surface* screen) {
	if( image  == NULL )
	{
		image = load_image( "Images/Player.jpg" );
	}

	apply_surface( box.x, box.y, image, screen );
}

SDL_Rect* Exit::get_rect() {
	return &box;
}

Exit::~Exit() {
	std::cerr << "  " << std::endl << " Exit " << std::endl;
	delete image;
	image = NULL;

}
