/*
 * Game.cpp
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#include "Game.h"
#include "Player.h"
#include "Wall.h"
#include "Level.h"
#include "Timer.h"
#include "Menu.h"

#include <iostream>
#include <string>

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;
const int SCREEN_BPP = 32;
const int FRAMES_PER_SECOND = 50;

Game::Game() {
	/**
	 * Game constructor
	 * Sets the pointer values to null.
	 */
	screen = NULL;
}

bool Game::init() {
	/**
	 * Initialise the screen and font variables
	 * @return Return true if everything initalitsed ok, otherwise return false
	 */

    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;
    }

    //Set the window caption
    SDL_WM_SetCaption( "Maze of death", NULL );

    if( TTF_Init() == -1 )
	{
		return false;
	}

    //If everything initialized fine
    return true;
}

void Game::clean_up() {
	/**
	 * Cleans up the SDL enviroment.
	 */

    //Quit SDL
    SDL_Quit();
}

int Game::run() {
	/**
	 * Function that runs the game and manage menu and start levels.
	 * @return Error code
	 */

	// Make sure the program waits for a quit
	quit = false;

	// Initialize
	if( init() == false )
	{
		// IF intialize fails return 1.
		return 1;
	}

	// Keep track of the current frame
	int frame = 0;

	// Fps regulator
	Timer fps;

	// Keep track on the time
	Timer timer;

	// Initialize Gamerule
	Gamerules game_rules;
	Gamerules& game_rules_pointer = game_rules;
	std::vector<Sprite*> first_level_objects;

	// Initialize level
	Level level(screen,game_rules_pointer,"Fictious level");

	// Initialize menu
	Menu menu(screen, timer);
	bool menu_initialzied = false;

	//Game loop, While the user hasn't quit
	while( quit == false )
	{
		fps.start();
		//Initialize main_menu when game starts
		if(menu_initialzied == false)
		{
			menu_initialzied = true;
			menu.main_menu();
		}

		//While there's an event to handle
		while( SDL_PollEvent( &event ) )
		{
			handle_menu_events(level, menu, timer, quit);
		}

		//Game logic, used when a level is started
		if (!timer.is_paused() && timer.is_started() )
		{
			//Grab reference to player, from level
			Player& player = level.get_player();

			//Fill background white
			SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );

			/* Handle events logic for player */
			player.handle_events_state();

			/* Handle movement */
			level.move_moving_sprites();

			/* Draw objects on screen */
			level.draw_game_objects();

		}

		// Draw image, displaying win or game over
		if( game_rules.has_won() )
		{
			menu.draw_end_image("Images/end_message-win.png");
			timer.pause();
		}
		else if( game_rules.has_been_killed() )
		{
			menu.draw_end_image("Images/end_message-game_over.png");
			timer.pause();
		}

		// Update the screen
		if( SDL_Flip( screen ) == -1 )
		{
			return 1;
		}

		// Increment the frame counter
		frame++;

		//Limit FPS
		if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
		{
			SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
		}

		//Return to menu, if player have won or been killed
		if(game_rules.has_won() == true || game_rules.has_been_killed() == true)
		{
			return_to_menu(game_rules, menu, timer);
		}
	}

	//Free the surface and quit SDL
	clean_up();

	return 0;
}

void Game::return_to_menu(Gamerules& game_rules, Menu& menu, Timer& timer) {
	/*
	 * Return to main_menu after end_message have been shown for END_MESSAGE_TIME_SECONDS
	 * @param game_rules The game rules that applies to the level.
	 * @param menu The menu object
	 * @param timer The timer object
	 */
	const int END_MESSAGE_TIME_SECONDS = 2;
	SDL_Delay(END_MESSAGE_TIME_SECONDS*1000);
	// Reset values and enters the menu
	menu.main_menu();
	game_rules.reset_status();
	game_rules.reset();
	timer.stop();
}

void Game::handle_menu_events(Level& level, Menu& menu, Timer& timer, bool& quit) {
	/*
	 * Handle game pausing, opening menu and calling menu's event handler
	 * @param level The level that is in use
	 * @param menu The menu to be used
	 * @param timer The timer that is being used
	 * @param quit Bool varaiable to see if the game should exit
	 */

	//Pause and unpause
	if( event.type == SDL_KEYDOWN )
	{
		if( event.key.keysym.sym == SDLK_p )
		{
			if( timer.is_paused() == true )
			{
				timer.unpause();
			} //Unpause
			else
			{
				timer.pause();
			} //Pause the timer
		}

		if( event.key.keysym.sym == SDLK_ESCAPE)
		{
			if( timer.is_paused() == true )
			{
				timer.unpause();
			} //Unpause
			else
			{
				timer.pause();
				menu.main_menu();
			}
		}

		if( timer.is_paused() == true || timer.is_started() == false)
		{
			//Timer isn't started if no level is loaded
			menu.handle_events(&event, quit, level);
		}
	}


	 if( event.type == SDL_QUIT )
	 {
		//Quit the program
		quit = true;
	 }
}

Game::~Game() {
	/**
	 * delete and sets the screen variable to null.
	 */
	delete screen;
	screen = NULL;
}
