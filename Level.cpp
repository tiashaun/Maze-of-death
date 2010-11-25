/*
 * Level.cpp
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#include "Level.h"
#include "Wall.h"

#include <iterator>

Level::Level() {


}

void Level::fictious_level()
{
/*
	for(int y = 100; y < 500; y += 10)
		game_objects.push_back(new Wall(100,y));

	std::vector<Sprite*>::iterator it;
	for(it = game_objects.begin() ; it != game_objects.end(); it++)
	{
		(*it)->show();
	}*/

	Wall wall(100,100);
}


Level::~Level() {

}
