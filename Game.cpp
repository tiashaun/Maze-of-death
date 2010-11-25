/*
 * Game.cpp
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#include "Game.h"
#include "Player.h"
#include "Wall.h"

#include "SDL/SDL.h"

#include <iostream>
#include <string>

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;
const int SCREEN_BPP = 32;

Game::Game()
{
	SDL_Surface *screen = NULL; //The event structure that will be used
}

bool Game::init()
{
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

    //If everything initialized fine
    return true;
}

void Game::clean_up()
{

    //Quit SDL
    SDL_Quit();
}

int Game::run()
{
	 //Make sure the program waits for a quit
	bool quit = false;

	//Initialize
	if( init() == false )
	{
		return 1;
	}

	Player player;
	//Wall wall_obj(300,100);

	//While the user hasn't quit
	while( quit == false )
	{
		//While there's an event to handle
		while( SDL_PollEvent( &event ) )
		{

			//player.handle_events_press(event);

			 if( event.type == SDL_QUIT )
			 {
				//Quit the program
				quit = true;
			 }

		}
		//level.handle_events();
		player.handle_events_state();

		SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );

		//Apply the surface to the screen
		//level.show(*screen);
		player.show(screen);
		//wall_obj.show(screen);

		//Update the screen
		if( SDL_Flip( screen ) == -1 )
		{
			return 1;
		}

		SDL_Delay(100);
	}

	//Free the surface and quit SDL
	clean_up();

	return 0;
}

Game::~Game()
{

}
