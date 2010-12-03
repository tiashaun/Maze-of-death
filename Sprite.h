/*
 * Sprite.h
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#ifndef SPRITE_H_
#define SPRITE_H_
#include "SDL/SDL.h"
class Level;
#include <string>

class Sprite {
public:
	Sprite(Level& level);
	virtual ~Sprite();
	virtual void show( SDL_Surface* ) = 0;
	bool write_to_screen( SDL_Surface* screen, std::string filename, int x_coordinate, int y_coordinate);
	void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );
	virtual SDL_Rect* get_rect() = 0;
	SDL_Surface* load_image( std::string filename );


	std::string image_path;

	void set_level(Level& level);
	void set_is_object_movable(bool is_moveable);
	void set_type(std::string type);

	Level& get_level();
	bool is_object_movable();
	std::string get_type();

private:
	Level& level;						// The level this object is on.
	bool is_movable;
	std::string type;
};

#endif /* SPRITE_H_ */
