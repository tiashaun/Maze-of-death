/*
 * Menu.h
 *
 *  Created on: Dec 6, 2010
 *      Author: proxz
 */

class SDL_Surface;
#include "SDL/SDL_ttf.h"
class Timer;
#include <string>
#include <vector>

#ifndef MENU_H_
#define MENU_H_

class Menu {
public:
	Menu(SDL_Surface *screen);
	virtual ~Menu();
	void main_menu();
	void handle_events(SDL_Event* event, Timer*, bool&);
private:
	void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );
	SDL_Surface* load_image( std::string filename );
	bool write_to_screen( SDL_Surface* screen, std::string filename, int x_coordinate, int y_coordinate);
	void render_text_items(std::vector<std::string>&);
	bool init_menu(SDL_Surface *screen);
	void select_menu_item(bool next_item);

	SDL_Surface* screen;
	uint menu_item_highlighted;
	TTF_Font* font;
	std::vector<std::string> menu_items;
};

#endif /* MENU_H_ */
