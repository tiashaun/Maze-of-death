/*
 * Menu.cpp
 *
 *  Created on: Dec 6, 2010
 *      Author: proxz
 */

#include "Menu.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <iostream>

const int MENU_X_COORDINATE = 300;
const int MENU_Y_COORDINATE_START = 220;
const int FONT_SIZE = 80;
const int FONT_LINE_SEPARATION = 20;

Menu::Menu(SDL_Surface *screen) : screen(screen) {
	TTF_Font *font = NULL;
}

void Menu::main_menu() {
	SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0x00, 0x00, 0x00 ) );

	write_to_screen(screen, "Images/main_menu.png", 80, 40);
	std::vector<std::string> main_menu_items;

	main_menu_items.push_back("Fugly");
	main_menu_items.push_back("Do you dare");
	main_menu_items.push_back("Exit");

	render_text_items(main_menu_items);
}

void Menu::render_text_items(std::vector<std::string> text_items)
{
	SDL_Color textColor = { 255, 255, 255 };

	int write_surface_at = MENU_Y_COORDINATE_START;

	std::vector<std::string>::iterator it;
	SDL_Surface *message = NULL;

	font = TTF_OpenFont( "Extra/Times_New_Roman.ttf", FONT_SIZE );

	for( it = text_items.begin(); it != text_items.end(); it++)
	{

		const char *text_item_cstring = (char*)(*it).c_str();

		message = TTF_RenderText_Solid( font, text_item_cstring, textColor );

		apply_surface( MENU_X_COORDINATE, write_surface_at, message, screen );
		write_surface_at += FONT_SIZE + FONT_LINE_SEPARATION;

	}
}

void Menu::ingame_menu() {

}

void Menu::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination ) {
    //Temporary rectangle to hold the offsets
    SDL_Rect offset;

    //Get the offsets
    offset.x = x;
    offset.y = y;

    //Blit the surface
    SDL_BlitSurface( source, NULL, destination, &offset );
}

SDL_Surface* Menu::load_image( std::string filename ) {
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

bool Menu::write_to_screen( SDL_Surface* screen, std::string filename, int x_coordinate, int y_coordinate) {
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

Menu::~Menu() {
	// TODO Auto-generated destructor stub
}
