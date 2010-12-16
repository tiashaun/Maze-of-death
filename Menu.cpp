/*
 * Menu.cpp
 *
 *  Created on: Dec 6, 2010
 *      Author: proxz
 */

#include "Menu.h"
#include "Timer.h"
#include "Level.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <iostream>

const int MENU_X_COORDINATE = 300;			//<! X-coordinate, to print menu items at
const int MENU_Y_COORDINATE_START = 220;	//<! Y-coordinate, to print the first menu item at
const int MENU_FONT_SIZE = 80;				//<! Pixel font size for menu items
const int RESUME_FONT_SIZE = 25;			//<! Font size for resume text
const int FONT_LINE_SEPARATION = 20;		//<! Number of pixels between menu items
const int RESUME_TEXT_X_COORDINATES = 45;	//<! X-coordinate, to print resume text at
const int RESUME_TEXT_Y_COORDINATES = 20;	//<! Y-coordinate, to print resume text at
const int END_IMAGE_X_COORDINATE = 280;		//<! X-coordinate, to print gameover/win image at
const int END_IMAGE_Y_COORDINATE = 260;		//<! Y-coordinate, to print gameover/win image at
const char *FONT_TYPE =  "Extra/Times_New_Roman.ttf"; //<! Font type for all text


Menu::Menu(SDL_Surface *screen, Timer &timer) : screen(screen), timer(timer)  {
	font = NULL;
}

void Menu::main_menu() {
	/**
	 * Initialize main menu variables, and call rendering of menu items
	 */

	menu_item_highlighted = 0;

	if(init_menu(screen) == false)
	{
		throw("Could not initialize menu");
	}

	render_text_items(menu_items);
}

void Menu::render_text_items(std::vector<std::string>& menu_items) {
	/**
	 * Render all text items in menu
	 *
	 * @param menu_items Contains all menu items to render
	 */
	SDL_Color text_color = { 255, 255, 255 }; 		  //Regular text color
	SDL_Color text_color_highlighted = { 255, 1, 1 }; //Highlighted text color

	font = TTF_OpenFont( FONT_TYPE, MENU_FONT_SIZE );

	render_menu_items(text_color, text_color_highlighted);

	//Write resume text if it's a paused game
	if(timer.is_paused() == true )
	{
		render_resume_text(text_color);
	}
}

void Menu::render_menu_items(SDL_Color& text_color, SDL_Color& text_color_highlighted) {
	/**
	 * Render all menu items in menu_items vector and write to screen
	 *
	 * @param text_color Text color normal text
	 * @param text_color_highlighted Text color highlighted text-item
	 */

	int write_surface_item_at = MENU_Y_COORDINATE_START; 	 //Y-coordinate where first menu_item is written
	std::vector<std::string>::iterator it;
	SDL_Surface *message = NULL; 							 //Temporary storage message
	size_t object_index = 0; 								 //Index current processed text-item

	//Write all text items to screen
	for( it = menu_items.begin(); it != menu_items.end(); it++)
	{
		const char *text_item_cstring = (char*)(*it).c_str(); //Text item as c-string (char array)

		//Regular text color
		if(object_index != menu_item_highlighted)
			message = TTF_RenderText_Solid( font, text_item_cstring, text_color );
		//Highlighted item
		else if( object_index == menu_item_highlighted)
			message = TTF_RenderText_Solid( font, text_item_cstring, text_color_highlighted );

		apply_surface( MENU_X_COORDINATE, write_surface_item_at, message, screen );
		write_surface_item_at += MENU_FONT_SIZE + FONT_LINE_SEPARATION; 	//Y-coordinate for next menu item

		object_index++;
	}
}

void Menu::render_resume_text(SDL_Color& text_color) {
	/**
	 * Render resume text in menu
	 *
	 * @param text_color Message text color
	 */
	SDL_Surface *message = NULL; 						//Rendered text, temporary storage
	font = TTF_OpenFont( FONT_TYPE, RESUME_FONT_SIZE ); //Initialize font

	message = TTF_RenderText_Solid( font, "Press ESCAPE to resume", text_color );
	apply_surface( RESUME_TEXT_X_COORDINATES, RESUME_TEXT_Y_COORDINATES, message, screen );
}

void Menu::handle_events(SDL_Event* event, bool& quit, Level& level) {
	/**
	 * Handle events in the menu
	 *
	 * @param event Main screen object which all graphics is drawn on
	 * @param quit If quit == false, game is terminated
	 * @param level Reference to the level object
	 */

	//Highlight the menu_item one step down in the list
	if( event->key.keysym.sym == SDLK_DOWN)
	{
		bool next_item = true;
		select_menu_item(next_item);
		render_text_items(menu_items);
	}

	//Highlight the menu_item one step up in the list
	if( event->key.keysym.sym == SDLK_UP)
	{
		bool next_item = false;
		select_menu_item(next_item);
		render_text_items(menu_items);
	}

	if( event->key.keysym.sym == SDLK_RETURN)
	{
		//Quit game if at the last menu_item, which always is Exit
		if( menu_item_highlighted == menu_items.size()-1 )
		{
			quit = true;
		}
		//Load level1 and start game
		else if(menu_item_highlighted == 0)
		{

			level.clear_level();

			level.level1();
			timer.start();
		}
		//Load level2 and start game
		else if(menu_item_highlighted == 1)
		{
			level.clear_level();
			level.level2();
			timer.start();
		}

	}
}

void Menu::draw_end_image(const char *image) {
	/**
	 * Draw end image on screen
	 * @param image Filename and path for image to draw
	 */
	write_to_screen(screen, image, END_IMAGE_X_COORDINATE, END_IMAGE_Y_COORDINATE);
}

void Menu::select_menu_item(bool next_item) {
	/*
	 * Select and highlight next item or one item back in the menu_items vector
	 *
	 * @param next_item Highlight next or on item back, in the menu_items vector
	 */

	if( next_item == true)
		menu_item_highlighted++;
	else if( next_item == false)
		menu_item_highlighted--;

	menu_item_highlighted = menu_item_highlighted % menu_items.size();
}

bool Menu::init_menu(SDL_Surface *screen) {
	/*
	 * Initialize menu:
	 * Put black background and background picture on screen
	 * Create menu_items vector
	 *
	 * @param screen Main screen object which all graphics is drawn on
	 * @return bool Flags if background image was successfully written to screen
	 */
	SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0x00, 0x00, 0x00 ) );

	if(write_to_screen(screen, "Images/main_menu.png", 80, 40) == false)
	{
		return false;
	}

	//Create the menu items, if not already created
	if(menu_items.empty() )
	{
		menu_items.push_back("Easymode");
		menu_items.push_back("Hardmode");
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
	/**
	 * Load an image and process it with SDL functions
	 * Which creates an object to draw on screen
	 * @param filename Filename and path for image to process
	 * @return optimized image object
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

bool Menu::write_to_screen( SDL_Surface* screen, std::string filename, int x_coordinate, int y_coordinate) {
	/*
	 * Draw image on screen
	 * @param screen Main screen object which all graphics is drawn on
	 * @param filename Filename and path for image to draw
	 * @param x_coordinate Start x-coordinate to draw image at
	 * @param y_coordinate Start y-coordinate to draw image at
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
