/*
 * Level.cpp
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#include "Level.h"
#include "Wall.h"

Level::Level(SDL_Surface* destination) : destination(destination){
	fictious_level();
}

void Level::fictious_level()
{

	for(int y = 100; y < 500; y += 10)
		game_objects.push_back(new Wall(100,y));

	for(int y = 100; y < 500; y += 10)
			game_objects.push_back(new Wall(y,100));

	for(int y = 100; y < 500; y += 10)
				game_objects.push_back(new Wall(y,500));

	for(int y = 100; y < 500; y += 10)
			game_objects.push_back(new Wall(500,y));

}

void Level::draw_game_objects()
{
	std::vector<Sprite*>::iterator it;
	for(it = game_objects.begin() ; it != game_objects.end(); it++)
	{
		(*it)->show(destination);
	}
}

Level::~Level() {

}
