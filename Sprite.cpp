/*
 * Sprite.cpp
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#include "Sprite.h"
#include <SDL/SDL_image.h>

Sprite::Sprite() {

}

void Sprite::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
    //Temporary rectangle to hold the offsets
    SDL_Rect offset;

    //Get the offsets
    offset.x = x;
    offset.y = y;

    //Blit the surface
    SDL_BlitSurface( source, NULL, destination, &offset );
}

SDL_Surface* Sprite::load_image( std::string filename )
{
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

bool Sprite::write_to_screen( SDL_Surface* screen, std::string filename, int x_coordinate, int y_coordinate)
{
	/*
	 * Draw object on screen
	 * @param screen
	 */

	SDL_Surface *image = NULL;

	image = load_image( filename );

	if( image  == NULL )
	{
		return false;
	}

	apply_surface( x_coordinate, y_coordinate, image, screen); //Draw on screen
	return true;
}

bool Sprite::is_object_moveable()
{
	return is_moveable;
}

Sprite::~Sprite() {

}
