/*
 * Player.cpp
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#include "Enemy_Unreactive.h"
#include "Game.h"
#include <vector>

const int Enemy_Reactive_WIDTH = 35;	// Enemy's SDL_rectangle width
const int Enemy_Reactive_HEIGTH = 35;	// Enemy's SDL_rectangle heigth

Enemy_Unreactive::Enemy_Unreactive(Level& level , int x_start_coordinate, int y_start_coordinate, float speed,	std::vector<Node*> *nodes)
	: Enemy(level, speed, nodes), gamerules(get_level().get_gamerules()) {
	/**
	 * Constructor for Enemy_Reactive.
	 * @param level The level object that the object will belong to
	 * @param x_start_coordinate The x position the object should start on
	 * @param y_start_coordinate The y position the object should start on
	 * @param speed The speed that the object will have on the level, provided as a float.
	 * @param nodes The nodes that the enemy can follow, can be provided as an empty vector.
	 * @return An Enemy_Unreactive object
	 */

	set_is_object_movable(true);		// Parameter to detect if the object is a moveable sprite
	set_type("Enemy_Unreactive");		// Type name used to identify this enemy.
	box.x = x_start_coordinate;			// Enemy's SDL_Rect, x-coordinate
	box.y = y_start_coordinate;			// Enemy's SDL_Rect, y-coordinate
	box.w = Enemy_Reactive_WIDTH;		// Enemy's SDL_Rect, width
	box.h = Enemy_Reactive_HEIGTH;		// Enemy's SDL_Rect, height
	image = NULL;						// Initialise the image pointer to null for safety.
}


void Enemy_Unreactive::update() {
	/**
	*  Controlls and update the enemys movement.
	*/

	// Move to next node and update x y coord.
	move_to_target_node();
	move();

	// Store type of colliding objects
	std::vector<std::string> colliding_objects_type; //Store type of colliding objects
	colliding_objects_type = get_level().check_collisions(this);

	// Check if the enemy collide with something it can't collide with.
	if( !colliding_objects_type.empty()
		&&	get_level().get_gamerules().can_move(get_type(), colliding_objects_type ) == false)
	{
		// If it does, take him back to last position
		box.x -= get_xVelocity();
		box.y -= get_yVelocity();
	}
	else
	{
		// He dosn't collide with anything and dosn't need to be moved back.
	}

}

void Enemy_Unreactive::show( SDL_Surface* screen) {
	/**
	 * Draw Enemy_Unreactive object on screen
	 * @param screen The screen object that the images draws on.
	 */

	// Check is image does not exist
	if( image  == NULL )
	{
		// If it doesn't exist load image.
		image = load_image( "Images/spöke.bmp" );
	}

	// Draw image on screen object
	apply_surface( box.x, box.y, image, screen );

}

Enemy_Unreactive::~Enemy_Unreactive() {
	/**
	 * Frees the image memory.
	 */
	// Check if the object has an image
	if(image != NULL)
	{
		// if it has free the memory space.
		SDL_FreeSurface(image);
	}
}
