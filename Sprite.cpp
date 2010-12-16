/*
 * Sprite.cpp
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#include "Sprite.h"
#include "Level.h"
#include "Gamerules.h"
#include <SDL/SDL_image.h>
#include <iostream>

Sprite::Sprite(Level& level)
	: level(level) {
    /**
     * Constructor for Sprite. Base class for all Sprites.
     * @param The level that the object is on.
     * @warning This is an abstract class and should not be instantiated.
     */

}

void Sprite::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination ) {
    /**
     * Draws the object on the screen.
     * @param x The x value where the object should be on the destination
     * @param y The y value where the object should be on the destination
     * @param source The source object, can be an image.
     * @param destination The destination where to drawn on.
     */
    SDL_Rect offset;

    //Get the offsets
    offset.x = x;
    offset.y = y;

    //Blit the surface
    SDL_BlitSurface( source, NULL, destination, &offset );
}

SDL_Surface* Sprite::load_image( std::string filename ) {
	/**
	 * Loads an image and performce safety checks.
	 * @param filename The file path to where the image exist.
	 * @return Returns the image as a SDL_Surface pointer.
	 */
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old image
        SDL_FreeSurface( loadedImage );
    }

    //Return the optimized image
    return optimizedImage;
}

bool Sprite::is_object_movable() {
	/**
	 * Check if the object can move
	 * @return Return true if the object can move at all, otherwise return false.
	 */
	return is_movable;
}

void Sprite::set_is_object_movable(bool is_movable) {
	/**
	 * Set if the object should be able to move
	 * @param is_movable True or false as a boolean.
	 */
	this->is_movable=is_movable;
}
void Sprite::set_type(std::string type) {
	/**
	 * Sets the type that the object is refered as.
	 * @param type The type name as a string.
	 */
	this->type=type;
}

Level& Sprite::get_level() {
	/**
	 * Returns the level that the object is on.
	 * @return Level object.
	 */
	return level;
}
std::string Sprite::get_type() {
	/**
	 * Returns the type of the object.
	 * @return Returns the type of the object.
	 */
	return type;
}

Sprite::~Sprite() {
	/**
	 * Destructor for Sprite.
	 */

}
