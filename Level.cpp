/*
 * Level.cpp
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#include "Level.h"
#include "Wall.h"
#include "Player.h"

#include <exception>

Level::Level(SDL_Surface* destination) : destination(destination){
	//Load fictious level
	fictious_level();
}

void Level::fictious_level()
{
	game_objects.push_back(new Player(*this));

	for(int y = 100; y < 500; y += 10)
		game_objects.push_back(new Wall(100, y));

	for(int y = 100; y < 500; y += 10)
		game_objects.push_back(new Wall(y, 100));

	for(int y = 100; y < 500; y += 10)
		game_objects.push_back(new Wall(y, 500));

	for(int y = 100; y < 500; y += 10)
		game_objects.push_back(new Wall(500, y));
}

void Level::draw_game_objects()
{
	std::vector<Sprite*>::iterator it;
	for(it = game_objects.begin() ; it != game_objects.end(); it++)
	{
		(*it)->show(destination);
	}
}

std::vector<std::string> Level::check_collisions(Sprite* object_to_check)
{
	std::vector<std::string> colliding_objects_type;
	std::vector<Sprite*>::iterator it;

	for( it=game_objects.begin(); it != game_objects.end(); it++)
	{
		if( (*it)->get_type() != "Player")
		{

			if( check_collision(object_to_check->get_rect(), (*it)->get_rect() ) == true )
			{
				std::string object_type = (*it)->get_type();
				colliding_objects_type.push_back(object_type);
			}
		}
	}
	return colliding_objects_type;
}


bool Level::check_collision(SDL_Rect* A, SDL_Rect* B)
{
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = A->x;
	rightA = A->x + A->w;
	topA = A->y;
	bottomA = A->y + A->h;

	//Calculate the sides of rect B
	leftB = B->x;
	rightB = B->x + B->w;
	topB = B->y;
	bottomB = B->y + B->h;

	//If any of the sides from A are outside of B
	if( bottomA <= topB )
	{
		return false;
	}

	if( topA >= bottomB )
	{
		return false;
	}

	if( rightA <= leftB )
	{
		return false;
	}

	if( leftA >= rightB )
	{
		return false;
	}

	//If none of the sides from A are outside B return true;
	return true;
}

Player& Level::get_player()
{
	std::vector<Sprite*>::iterator it;
	for(it = game_objects.begin() ; it != game_objects.end(); it++)
	{
		if( (*it)->get_type() == "Player")
		{
			//Sprite* player_sprite = *it;
			Player* player = dynamic_cast<Player*> ( (*it) ); //Implement "moving sprite" and and show as virtual..
			return *player;
		}
	}
	//Borde returna false eller "throw exception" ifall ingen spelare finns.
}


Level::~Level() {

}
