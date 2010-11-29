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
	virtual bool show( SDL_Surface* ) = 0;
	void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );
	virtual SDL_Rect* get_rect() = 0;
	SDL_Surface* load_image( std::string filename );
	virtual std::string get_type() = 0;
};

#endif /* SPRITE_H_ */
