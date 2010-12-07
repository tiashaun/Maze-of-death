/*
 * Menu.cpp
 *
 *  Created on: Dec 6, 2010
 *      Author: proxz
 */

#include "Menu.h"
#include "Timer.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <iostream>

const int MENU_X_COORDINATE = 300;
const int MENU_Y_COORDINATE_START = 220;
const int FONT_SIZE = 80;
const int RESUME_TEXT_SIZE = 25;
const int FONT_LINE_SEPARATION = 20;
const char *FONT_TYPE =  "Extra/Times_New_Roman.ttf";


Menu::Menu(SDL_Surface *screen, Timer &timer) : screen(screen), timer(timer)  {
	TTF_Font *font = NULL;
}

void Menu::main_menu() {

	menu_item_highlighted = 0;

	if(init_menu(screen) == false)
	{
		throw("Could not initialize menu");
	}

	render_text_items(menu_items);
}

void Menu::render_text_items(std::vector<std::string>& menu_items) {

	SDL_Color text_color = { 255, 255, 255 }; //Regular text color
	SDL_Color text_color_highlighted = { 255, 1, 1 }; //Highlighted text color

	font = TTF_OpenFont( FONT_TYPE, FONT_SIZE );

	render_menu_items(text_color, text_color_highlighted);

	//Write resume text if it's a paused game
	if(timer.is_paused() == true )
	{
		render_resume_text(text_color);
	}
}

void Menu::render_menu_items(SDL_Color& text_color, SDL_Color& text_color_highlighted)
{
	int write_surface_item_at = MENU_Y_COORDINATE_START;
	std::vector<std::string>::iterator it;
	SDL_Surface *message = NULL;
	size_t object_index = 0; //Current processed item

	//Write all text items to screen
	for( it = menu_items.begin(); it != menu_items.end(); it++)
	{
		const char *text_item_cstring = (char*)(*it).c_str(); //Text item as c-string (char array)

		//Regular text color
		if(object_index != menu_item_highlighted)
			message = TTF_RenderText_Solid( font, text_item_cstring, text_color );
		//Highlighted text color
		else
			message = TTF_RenderText_Solid( font, text_item_cstring, text_color_highlighted );

		apply_surface( MENU_X_COORDINATE, write_surface_item_at, message, screen );
		write_surface_item_at += FONT_SIZE + FONT_LINE_SEPARATION; 	//Y-coordinate for next item

		object_index++;
	}
}

void Menu::render_resume_text(SDL_Color& textColor)
{
	SDL_Surface *message = NULL;
	font = TTF_OpenFont( FONT_TYPE, RESUME_TEXT_SIZE );
	message = TTF_RenderText_Solid( font, "Press ESCAPE to resume", textColor );
	const int RESUME_TEXT_X = 45;
	const int RESUME_TEXT_Y = 20;
	apply_surface( RESUME_TEXT_X, RESUME_TEXT_Y, message, screen );
}

void Menu::handle_events(SDL_Event* event, bool& quit) {
	if( event->key.keysym.sym == SDLK_DOWN)
	{
		bool next_item = true;
		select_menu_item(next_item);
	}

	if( event->key.keysym.sym == SDLK_UP)
	{
		bool next_item = false;
		select_menu_item(next_item);
	}

	if( event->key.keysym.sym == SDLK_RETURN)
	{
		//Quit game if at the last menu_item, which always is Exit
		if( menu_item_highlighted == menu_items.size()-1 )
		{
			quit = true;
		}
		else
		{
			//Load current selected level
		}
	}
}

void Menu::select_menu_item(bool next_item) {
	/*
	 * Select and highlight menu_item, next item or the item before
	 */

	if( next_item == true)
		menu_item_highlighted++;
	else
		menu_item_highlighted--;

	menu_item_highlighted = menu_item_highlighted % menu_items.size();
	render_text_items(menu_items);
}

bool Menu::init_menu(SDL_Surface *screen) {
	/*
	 * Initialize menu:
	 * Put black background, background picture on screen
	 * Create menu_items
	 */

	SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0x00, 0x00, 0x00 ) );

	if(write_to_screen(screen, "Images/main_menu.png", 80, 40) == false)
	{
		return false;
	}

	//Create the menu items, if not already created
	if(menu_items.empty() )
	{
		menu_items.push_back("Fugly");
		menu_items.push_back("Do you dare");
		menu_items.push_back("Exit");
	}

	return true;
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

}
