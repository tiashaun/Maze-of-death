/*
 * Wall.cpp
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#include "Wall.h"

const int Wall_WIDTH = 10;
const int Wall_HEIGTH = 10;

Wall::Wall(	Level& level, Gamerules& gamerules, int x, int y) : level(level), gamerules(gamerules)
{
	is_moveable = false;
	box.x = x;
	box.y = y;
	box.w = Wall_WIDTH;
	box.h = Wall_HEIGTH;
	type = "Wall";
}

void Wall::show(SDL_Surface* screen)
{
	write_to_screen(screen, "Images/Wall.jpg", box.x, box.y);
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
