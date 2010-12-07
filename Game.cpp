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
const int FRAMES_PER_SECOND = 30;

Game::Game() {
	SDL_Surface *screen = NULL;
}

bool Game::init() {

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

    //Quit SDL
    SDL_Quit();
}

int Game::run() {
	//Make sure the program waits for a quit
	bool quit = false;

	//Initialize
	if( init() == false )
	{
		return 1;
	}

	//The frame rate regulator
	Timer timer;

	//Initialize Gamerule
	Gamerules game_rules;
	Gamerules& game_rules_pointer = game_rules;
	std::vector<Sprite*> first_level_objects;

	//Initialize level
	Level level(screen,game_rules_pointer,"Fictious level");
	//	Level *first_level = &level;
	//first_level_objects = fictious_level(first_level, game_rules_pointer);
	//level.fill_level();
	//Grab reference to player, from level
	Player& player = level.get_player();

	Menu menu(screen, timer);

	timer.start();

	//While the user hasn't quit
	while( quit == false )
	{
		//While there's an event to handle

		while( SDL_PollEvent( &event ) )
		{

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

				if( timer.is_paused() == true )
				{
					menu.handle_events(&event, quit);
				}
			}


			 if( event.type == SDL_QUIT )
			 {
				//Quit the program
				quit = true;
			 }
		}


		if (!timer.is_paused() )
		{
			//Fill background white
			SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );

			/* Handle events logic */
			player.handle_events_state();


			if(game_rules.has_won()==true)
			{
				break;
			}

			/* Handle movement */
			//player.move();
			level.move_moving_sprites();

			/* Draw objects on screen */
			level.draw_game_objects();
			//SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );


		}

		//Update the screen
		if( SDL_Flip( screen ) == -1 )
		{
			return 1;
		}

		//Limit FPS
		if( timer.get_ticks() < 1000 / FRAMES_PER_SECOND )
		{
			SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - timer.get_ticks() );
		}
	}


	//Free the surface and quit SDL
	clean_up();

	return 0;
}

Game::~Game() {
	screen = NULL;
}

std::vector<Sprite*> Game::fictious_level(Level *first_level, Gamerules& game_rules_pointer) {
	/*
	 *  Simple map to test different objects and collision detection
	 */
	/*
	std::vector<Sprite*> game_objects;
	game_objects.push_back(new Player(level, 2, gamerules));

	for(int y = 100; y < 500; y += 10)
		game_objects.push_back(new Wall(level, gamerules, 100, y));

	for(int y = 100; y < 500; y += 10)
		game_objects.push_back(new Wall(level, gamerules, y, 100));

	for(int y = 100; y < 500; y += 10)
		game_objects.push_back(new Wall(level, gamerules, y, 500));

	for(int y = 100; y < 500; y += 10)
		game_objects.push_back(new Wall(level, gamerules, 500, y));

	std::vector<Node*> *nodes1 = new std::vector<Node*>();
	nodes1->push_back(new Node(200,300));
	nodes1->push_back(new Node(400,300));
	game_objects.push_back(new Enemy_Unreactive(level, gamerules, 400, 300, 2, nodes1 ));

	game_objects.push_back(new Exit(*this, gamerules,400,200));


	std::vector<Node*> *nodes2 = new std::vector<Node*>();
	nodes2->push_back(new Node(300,300));
	nodes2->push_back(new Node(400,400));
	game_objects.push_back(new Enemy_Reactive(level, gamerules, 350, 300, 1, nodes2) );
	return game_objects;*/
}
