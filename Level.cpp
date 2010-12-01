/*
 * Level.cpp
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#include "Level.h"
#include "Moving_Sprite.h"
#include "Wall.h"
#include "Exit.h"
#include "Player.h"
#include "Enemy_Unreactive.h"
#include "Enemy_Reactive.h"
#include <iostream>

#include <exception>

Level::Level(SDL_Surface* destination, Gamerules& start_game_rules) : destination(destination), game_rules(start_game_rules){
	//Load fictious level
	fictious_level();
}

void Level::fictious_level()
{

	game_objects.push_back(new Player(*this, game_rules));

	for(int y = 100; y < 500; y += 10)
		game_objects.push_back(new Wall(*this, game_rules, 100, y));

	for(int y = 100; y < 500; y += 10)
		game_objects.push_back(new Wall(*this, game_rules, y, 100));

	for(int y = 100; y < 500; y += 10)
		game_objects.push_back(new Wall(*this, game_rules, y, 500));

	for(int y = 100; y < 500; y += 10)
		game_objects.push_back(new Wall(*this, game_rules, 500, y));


	//for(int y = 300; y < 400; y += 10)
	//	game_objects.push_back(new Wall(300, y));
	std::vector<int> xNodes (499,310);
	std::vector<int> yNodes (300,300);

<<<<<<< HEAD
	game_objects.push_back(new Enemy_Unreactive(*this, game_rules, 400, 300, 2, 0, xNodes, yNodes ));
=======
	game_objects.push_back(new Enemy_Unreactive(*this,400, 300, 2, 0, xNodes, yNodes ));
	game_objects.push_back(new Enemy_Reactive(*this,400, 400));
>>>>>>> 1743a66276c23a38aab0aeb36b70ee9f6f0c6068
}

void Level::move_moving_sprites()
{
	/**
    * Draw all game objects on the main SDL_Surface screen object
	*/
	std::vector<Sprite*>::iterator it;
	for(it = game_objects.begin() ; it != game_objects.end(); it++)
	{
		if( (*it)->is_object_moveable() == true)
		{
			Moving_Sprite* obje = dynamic_cast<Moving_Sprite*> ( (*it) );
			obje->update();
		}
	}
}

void Level::draw_game_objects()
{
	/**
	 * Draw all game objects on the main SDL_Surface screen object
	 */

	std::vector<Sprite*>::iterator it;
	for(it = game_objects.begin() ; it != game_objects.end(); it++)
	{
		(*it)->show(destination);
	}
}

std::vector<std::string> Level::check_collisions(Sprite* object_to_check)
{
	/**
	 * Check if any game objects collide with object_to_check
	 * @param object_to_check
	 */

	std::vector<std::string> colliding_objects_type; //Storage for colliding objects
	std::vector<Sprite*>::iterator it;

	for( it=game_objects.begin(); it != game_objects.end(); it++)
	{
		//Don't check for collision with self
		if( (*it) != object_to_check)
		{
			//If collision is detected, add the objects type to colliding_objects_type
			if( check_collision(object_to_check->get_rect(), (*it)->get_rect() ) == true )
			{
				std::string object_type = (*it)->get_type();
				colliding_objects_type.push_back(object_type);
			}
		}
	}
	return colliding_objects_type;
}


bool Level::check_collision(SDL_Rect* rectangle_A, SDL_Rect* rectangle_B)
{
	/**
	 *	Check if SDL_Rectangle A is colliding with SDL_Rectangle B
	 *
	 *	@param rectangle_A - Holds rectangle A's geometrics
	 *	@param rectangle_B - Holds rectangle B's geometrics
	 */

	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = rectangle_A->x;
	rightA = rectangle_A->x + rectangle_A->w;
	topA = rectangle_A->y;
	bottomA = rectangle_A->y + rectangle_A->h;

	//Calculate the sides of rect B
	leftB = rectangle_B->x;
	rightB = rectangle_B->x + rectangle_B->w;
	topB = rectangle_B->y;
	bottomB = rectangle_B->y + rectangle_B->h;

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
	/**
	 * Return a reference to the player object
	 */

	std::vector<Sprite*>::iterator it;
	for(it = game_objects.begin() ; it != game_objects.end(); it++)
	{
		if( (*it)->get_type() == "Player")
		{
			Player* player = dynamic_cast<Player*> ( (*it) );
			return *player;
		}
	}

	//If no player is found
	throw "No player object found, can't play the game";
}


Level::~Level() {

}
