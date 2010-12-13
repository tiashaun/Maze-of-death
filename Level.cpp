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
#include <cmath>
#include <omp.h>


struct Coordinates;

#include <exception>

Level::Level(SDL_Surface* screen, Gamerules& start_game_rules, std::string name)
	: screen(screen), gamerules(start_game_rules), name(name) {

}

void Level::fill_level(std::vector<Sprite*> new_game_objects){
	game_objects=new_game_objects;
}

void Level::clear_level() {
	/*
	 * Cleanup the level object by removing all game_objects
	 */
	/*
	int counter = 0;
	std::cerr << "  " << std::endl << game_objects.size();
	std::vector<Sprite*>::iterator it;
	for(it = game_objects.begin() ; it != game_objects.end(); it++)
	{

		std::cerr << counter << std::endl;
		counter++;
		delete *it;
		*it = NULL;
	}
	*/
	game_objects.clear();


}

void Level::level1() {
	/*
	 *  Simple map to test different objects and collision detection
	 */

	std::vector<Node*> *no_nodes = new std::vector<Node*>();
	game_objects.push_back(new Player(*this, 980,720, 2));

	// creates the edge walls
	for(int x = 0; x < 1020; x += 10)
		game_objects.push_back(new Wall(*this, x, 0));

	for(int y = 0; y < 760; y += 10)
		game_objects.push_back(new Wall(*this, 0, y));

	for(int x = 0; x < 1020; x += 10)
		game_objects.push_back(new Wall(*this, x, 760));

	for(int y = 0; y < 760; y += 10)
		game_objects.push_back(new Wall(*this, 1020, y));

	game_objects.push_back(new Exit(*this, 200,650));



	for(int x = 800; x < 1020; x += 10)
		game_objects.push_back(new Wall(*this, x, 700));


	for(int y = 580; y < 700; y += 10)
		game_objects.push_back(new Wall(*this, 800, y));

	std::vector<Node*> *nodes1 = new std::vector<Node*>();
	nodes1->push_back(new Node(750, 610));
	nodes1->push_back(new Node(750, 720));
	game_objects.push_back(new Enemy_Unreactive(*this, 750, 650, 2, nodes1 ));

	for(int y = 680; y < 760; y += 10)
		game_objects.push_back(new Wall(*this, 680, y));
	for(int y = 580; y < 630; y += 10)
			game_objects.push_back(new Wall(*this, 680, y));

	for(int x = 500; x < 680; x += 10)
		game_objects.push_back(new Wall(*this, x, 680));

	for(int x = 500; x < 680; x += 10)
			game_objects.push_back(new Wall(*this, x, 620));

	game_objects.push_back(new Enemy_Reactive(*this, 510, 630, 1, no_nodes) );

	for(int y = 620; y < 680; y += 10)
		game_objects.push_back(new Wall(*this, 500, y));


	for(int x = 10; x < 1020; x += 10)
		game_objects.push_back(new Wall(*this, x, 520));

	game_objects.push_back(new Enemy_Reactive(*this, 980, 550, 1, no_nodes) );
	game_objects.push_back(new Enemy_Reactive(*this, 980, 590, 1, no_nodes) );

	std::vector<Node*> *nodes3 = new std::vector<Node*>();
	nodes3->push_back(new Node(400, 540));
	nodes3->push_back(new Node(400, 710));
	game_objects.push_back(new Enemy_Unreactive(*this, 400, 550, 2, nodes3 ));

	std::vector<Node*> *nodes4 = new std::vector<Node*>();
	nodes4->push_back(new Node(300, 710));
	nodes4->push_back(new Node(300, 540));
	game_objects.push_back(new Enemy_Unreactive(*this, 300, 710, 2, nodes4 ));

	game_objects.push_back(new Enemy_Reactive(*this, 200, 580, 1, no_nodes) );



	std::vector<Node*> *nodes2 = new std::vector<Node*>();
	nodes2->push_back(new Node(300,300));
	nodes2->push_back(new Node(400,400));
	game_objects.push_back(new Enemy_Reactive(*this, 350, 300, 1, nodes2) );



}


void Level::level2() {
	/*
	 *  Simple map to test different objects and collision detection
	 */

	game_objects.push_back(new Player(*this, 600, 600, 2));

	for(int y = 100; y < 500; y += 10)
		game_objects.push_back(new Wall(*this, 100, y));

	for(int y = 100; y < 500; y += 10)
		game_objects.push_back(new Wall(*this, y, 100));

	for(int y = 100; y < 500; y += 10)
		game_objects.push_back(new Wall(*this, y, 500));

	for(int y = 100; y < 500; y += 10)
		game_objects.push_back(new Wall(*this, 500, y));

	std::vector<Node*> *nodes1 = new std::vector<Node*>();
	nodes1->push_back(new Node(200,300));
	nodes1->push_back(new Node(400,300));
	game_objects.push_back(new Enemy_Unreactive(*this, 400, 300, 2, nodes1 ));

	game_objects.push_back(new Exit(*this, 400,200));


	std::vector<Node*> *nodes2 = new std::vector<Node*>();
	nodes2->push_back(new Node(300,300));
	nodes2->push_back(new Node(400,400));
	game_objects.push_back(new Enemy_Reactive(*this, 350, 300, 1, nodes2) );
}

bool Level::line_of_sight(int object_x_coordinate, int object_y_coordinate,
		int target_x_coordinate, int target_y_coordinate, int allowed_distance){

	int direction_x = target_x_coordinate - object_x_coordinate;
	int direction_y = target_y_coordinate - object_y_coordinate;
	float hypotenuse = sqrt(direction_x * direction_x + direction_y * direction_y);
	if (hypotenuse > allowed_distance)
	{
		return false;
	}
	return true;
}

void Level::move_moving_sprites() {
	/**
    * Update state and position on created game objects
	*/
	// Starting the time measurement



	std::vector<Sprite*>::iterator it;
	for(it = game_objects.begin() ; it != game_objects.end(); it++)
	{
		if( (*it)->is_object_movable() == true)
		{
			Moving_Sprite* current_object_casted = dynamic_cast<Moving_Sprite*> ( (*it) );
			current_object_casted->update();
		}
	}
	// Measuring the elapsed time


}

void Level::draw_game_objects() {
	/**
	 * Draw all game objects on the main SDL_Surface screen object
	 */




	std::vector<Sprite*>::iterator it;
	for(it = game_objects.begin() ; it != game_objects.end(); it++)
	{
		int player_x = get_player().get_rect()->x;
		int player_y = get_player().get_rect()->y;
		bool allowed_to_draw = line_of_sight( player_x, player_y,
				(*it)->get_rect()->x, (*it)->get_rect()->y, 120);

		if (allowed_to_draw == true)
		{
			(*it)->show(screen);
		}
	}
}

std::vector<std::string> Level::check_collisions(Sprite* object_to_check) {
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


bool Level::check_collision(SDL_Rect* rectangle_A, SDL_Rect* rectangle_B) {
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



Player& Level::get_player() {
	/**
	 * Return a reference to the player object
	 */

	std::vector<Sprite*>::iterator it;
	for(it = game_objects.begin() ; it != game_objects.end(); it++)
	{
		//std::cerr << (*it)->get_type() << " hej";
		if( (*it)->get_type() == "Player")
		{
			Player* player = dynamic_cast<Player*> ( (*it) );
			return *player;
		}
	}

	//If no player is found
	throw "No player object found, can't play the game";
}

Gamerules& Level::get_gamerules() {
	return gamerules;
}


Level::~Level() {
	clear_level();
}
