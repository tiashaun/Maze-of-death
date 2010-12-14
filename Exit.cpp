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

Exit::Exit(	Level& level, int x_start_coordinate, int y_start_coordinate )
	: Sprite(level), gamerules(get_level().get_gamerules()) {
	/**
	 * Constructor for Enemy_Reactive.
	 * @param level The level object that the object will belong to
	 * @param x_start_coordinate The x position the object should start on
	 * @param y_start_coordinate The y position the object should start on
	 * @return An Exit object
	 */
	set_is_object_movable(false);					// Parameter to detect if the object is a moveable sprite
	set_type("Exit");								// Type name used to identify this enemy
	box.x = x_start_coordinate;						// Enemy's SDL_Rect, x-coordinate
	box.y = y_start_coordinate;						// Enemy's SDL_Rect, y-coordinate
	box.w = Exit_WIDTH;								// Enemy's SDL_Rect, width
	box.h = Exit_HEIGTH;							// Enemy's SDL_Rect, height
	image = NULL;									// Initialise the image pointer to null for safety.
}

void Exit::move() {
	/**
	 * Does nothing since the wall shouldn't move.
	 */
}

void Exit::update() {
	/**
	 * Does not need to update any values since the wall is not moving and does not initatie interaction.
	 */

}

void Exit::show(SDL_Surface* screen) {
	/**
	 * Draw Exit object on screen
	 * @param screen The screen object that the images draws on.
	 */

	// Check is image does not exist
	if( image  == NULL )
	{
		// If it doesn't exist load image.
		image = load_image( "Images/Player.jpg" );
	}

	// Draw image on screen object
	apply_surface( box.x, box.y, image, screen );
}

SDL_Rect* Exit::get_rect() {
	/**
	 * Get the SDL_Rect object that repersent the object
	 * @return The SDL_Rect object that repersent the object
	 */
	return &box;
}

Exit::~Exit() {
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
