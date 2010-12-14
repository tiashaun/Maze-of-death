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
	/**
	 * Constructor for level, just crateas a level object and intialize values accordign to the in parameters
	 * @param screen The screen object that the level draws objects on
	 * @param start_game_rules The gamerules that the level obides to
	 * @param name The name of the map
	 * @return Level object
	 */

}

void Level::fill_level(std::vector<Sprite*> new_game_objects){
	/**
	 * Fills the object with objects from the provided container.
	 * @param new_game_objects A coantianer with Sprite pointer objects
	 */
	game_objects=new_game_objects;
}

void Level::clear_level() {
	/**
	 * Cleanup the level object by removing all game_objects in the objects container
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
	/**
	 *  Simple map to test different objects and collision detection and provide a basic game experience
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
	/**
	 *  Simple map to test different objects and collision detection and provide a basic game experience
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
	/**
	 * Check if the second x and y coordinates pair are within allowed_distance from the first x and y coordinates pair.
	 * @param object_x_coordinate The first objects x values
	 * @param object_y_coordinate The first objects y values
	 * @param target_x_coordinate The first objects x values
	 * @param target_y_coordinate The second objects y values
	 * @param allowed_distance The maximum allowed distance between the object
	 * @return Returns true if the objects are under the allowed_distance, otherwise returns false
	 */

	// Calcualte the distance between the objects
	int direction_x = target_x_coordinate - object_x_coordinate;
	int direction_y = target_y_coordinate - object_y_coordinate;
	float hypotenuse = sqrt(direction_x * direction_x + direction_y * direction_y);
	// Check if the distance bewtween the objects are under the maximum allowed_distance
	if (hypotenuse > allowed_distance)
	{
		// If not return false
		return false;
	}
	// If under allowed_distance return true
	return true;
}

void Level::move_moving_sprites() {
	/**
    * Update state and position on created game objects
	*/

	// Go through all object on the level
	std::vector<Sprite*>::iterator it;
	for(it = game_objects.begin() ; it != game_objects.end(); it++)
	{
		// Check if the object can/is allowed to move
		if( (*it)->is_object_movable() == true)
		{
			// If so call the update function from the object
			Moving_Sprite* current_object_casted = dynamic_cast<Moving_Sprite*> ( (*it) );
			current_object_casted->update();
		}
	}
}

void Level::draw_game_objects() {
	/**
	 * Draw all game objects on the main SDL_Surface screen object
	 */

	// Go through all object on the level
	std::vector<Sprite*>::iterator it;
	for(it = game_objects.begin() ; it != game_objects.end(); it++)
	{
		// Get the x and y value of an object
		int player_x = get_player().get_rect()->x;
		int player_y = get_player().get_rect()->y;
		// Check if is is within the allowed_distance from the player object on the level.
		bool allowed_to_draw = line_of_sight( player_x, player_y,
				(*it)->get_rect()->x, (*it)->get_rect()->y, 120);

		if (allowed_to_draw == true)
		{
			// If it is then draw the object.
			(*it)->show(screen);
		}
	}
}

std::vector<std::string> Level::check_collisions(Sprite* object_to_check) {
	/**
	 * Check if any game objects collide with object_to_check
	 * @param object_to_check The object to check if it collides with anything
	 * @return Return a vector with the types of the object the object_to_check collides with
	 */

	std::vector<std::string> colliding_objects_type; //Storage for colliding objects
	std::vector<Sprite*>::iterator it;

	// Go through all object on the level
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
	 *	@return Returns true if the two objects collide, otherwise return false
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
	 * @return A reference to the player object on this level
	 */

	// Go through all object on the level
	std::vector<Sprite*>::iterator it;
	for(it = game_objects.begin() ; it != game_objects.end(); it++)
	{
		// Check if the object is a Player object
		if( (*it)->get_type() == "Player")
		{
			// If so return the player object
			Player* player = dynamic_cast<Player*> ( (*it) );
			return *player;
		}
	}

	//If no player is found
	throw "No player object found, can't play the game";
}

Gamerules& Level::get_gamerules() {
	/**
	 * Returns the gamerules that applies to this level.
	 * @return The gamerules that applies to this level.
	 */
	return gamerules;
}


Level::~Level() {
	/**
	 * Clear the container holding all the objects on the map and frees memory.
	 */
	clear_level();
}
