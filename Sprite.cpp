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

Sprite::Sprite(Level& level)
	: level(level) {

}

void Sprite::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination ) {
    //Temporary rectangle to hold the offsets
    SDL_Rect offset;

    //Get the offsets
    offset.x = x;
    offset.y = y;

    //Blit the surface
    SDL_BlitSurface( source, NULL, destination, &offset );
}

SDL_Surface* Sprite::load_image( std::string filename ) {
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
	return is_movable;
}

void Sprite::set_is_object_movable(bool is_movable) {
	this->is_movable=is_movable;
}
void Sprite::set_type(std::string type) {
	this->type=type;
}

Level& Sprite::get_level() {
	return level;
}
std::string Sprite::get_type() {
	return type;
}

Sprite::~Sprite() {

}
