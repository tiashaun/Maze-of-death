/*
 * Sprite.h
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#ifndef SPRITE_H_
#define SPRITE_H_
#include "SDL/SDL.h"
#include <string>

class Sprite {
public:
	Sprite();
	virtual ~Sprite();
	void show();
	void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );
	SDL_Surface* load_image( std::string filename );
};

#endif /* SPRITE_H_ */
