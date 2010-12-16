/*
 * Timer.cpp
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#include "Timer.h"

#include <SDL/SDL.h>

/*
 * Timer class for FPS regulation and Pausing the game
 */

Timer::Timer() {
    //Initialize the variables
    startTicks = 0;
    pausedTicks = 0;
    paused = false;
    started = false;
}

void Timer::start() {
	/**
	 * Start the timer
	 */
    started = true;
    paused = false;

    //Get the current clock time
    startTicks = SDL_GetTicks();
}

void Timer::stop() {
	/**
	 * Stop the timer
	 */
    started = false;
    paused = false;
}

void Timer::pause() {
	/**
	 * Pause the timer
	 */
    //If the timer is running and isn't already paused
    if( ( started == true ) && ( paused == false ) )
    {
        paused = true;
        pausedTicks = SDL_GetTicks() - startTicks;
    }
}

void Timer::unpause() {
	/**
	 * Unpause the timer
	 */
    if( paused == true )
    {
        paused = false;
        //Reset the starting ticks
        startTicks = SDL_GetTicks() - pausedTicks;

        //Reset the paused ticks
        pausedTicks = 0;
    }
}

int Timer::get_ticks() {
	/**
	 * Return current time
	 * @return if paused, return the time when it was paused
	 * if not paused, return current time minus the start time
	 */

    if( started == true )
    {
        if( paused == true )
        {
            //Return the number of ticks when the timer was paused
            return pausedTicks;
        }
        else
        {
            //Return the current time minus the start time
            return SDL_GetTicks() - startTicks;
        }
    }

    //If the timer isn't running
    return 0;
}

bool Timer::is_started() {
	/**
	 * Check if timer is started
	 * @return true if timer is started
	 */
    return started;
}

bool Timer::is_paused(){
	/**
	 * Check if timer is paused
	 * @return true if timer is stopped
	 */
    return paused;
}

Timer::~Timer() {

}
