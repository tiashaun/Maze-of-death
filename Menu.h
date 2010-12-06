/*
 * Menu.h
 *
 *  Created on: Dec 6, 2010
 *      Author: proxz
 */

class SDL_Surface;
#include "SDL/SDL_ttf.h"
#include <string>
#include <vector>

#ifndef MENU_H_
#define MENU_H_

class Menu {
public:
	Menu(SDL_Surface *screen);
	virtual ~Menu();
	void main_menu();
	void ingame_menu();

private:
	SDL_Surface* screen;
	void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );
	SDL_Surface* load_image( std::string filename );
	bool write_to_screen( SDL_Surface* screen, std::string filename, int x_coordinate, int y_coordinate);
	void render_text_items(std::vector<std::string> text_items);
	TTF_Font* font;
};

#endif /* MENU_H_ */
