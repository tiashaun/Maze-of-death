/*
 * Gamerules.cpp
 *
 *  Created on: Nov 29, 2010
 *      Author: proxz
 */

#include "Gamerules.h"
#include <iostream>

Gamerules::Gamerules() {
	/**
	 * Initialize values for gamerules.
	 */
	has_player_won = false;
	is_killed = false;
}

Gamerules::~Gamerules() {

}

void Gamerules::reset() {
	/**
	 * Reset Gamerules variables to start state.
	 */
	has_player_won = false;
	is_killed = false;
}

bool Gamerules::has_won() {
	/**
	 * Checks if the player has won.
	 * @return Returns true if the player has won, otherwise false
	 */
	return has_player_won;
}

bool Gamerules::has_been_killed() {
	/**
	 * Checks if the player is killed.
	 * @return Returns true if the player has been killed, otherwise false
	 */
	return is_killed;
}

void Gamerules::reset_status() {
	/**
	 * Reset Gamerules win state.
	 */
	has_player_won = false;
}

bool Gamerules::Player_checks(std::string type, std::vector<std::string>::iterator it) {
	/**
	 * Check if the player has collided with anything
	 * @param type The type to check with, must be "Player" for this function to have any effect.
	 * @param it The object to check against.
	 * @return Returns true if player does not collide with anything, otherwise returns false
	 */
	if(type == "Player" && *it == "Wall")
	{
	//	std::cerr << "Vägg!";
		return false;
	}
	if(type == "Player" && *it == "Enemy_Unreactive")
	{
	//	std::cerr << "dieee";
		is_killed = true;
		return true;
	}
	if(type == "Player" && *it == "Enemy_Reactive")
	{
	//	std::cerr << "dieee";
		is_killed = true;
		return true;
	}
	if(type == "Player" && *it == "Exit")
	{
		has_player_won=true;
		return true;
	}
//	type == "Enemy_Unreactive" && *it == "Player"
//	type == "Enemy_Reactive" && *it == "Player"
//	type == "Exit" && *it == "Player"
}

bool Gamerules::Enemy_Unreactive_checks(std::string type, std::vector<std::string>::iterator it) {
	/**
	 * Check if the Enemy_Unreactive has collided with anything
	 * @param type The type to check with, must be "Enemy_Unreactive" for this function to have any effect.
	 * @param it The object to check against.
	 * @return Returns true if Enemy_Unreactive does not collide with anything, otherwise returns false
	 */
	if(type == "Enemy_Unreactive" && *it == "Wall")
	{
		return false;
	}
	if(type == "Enemy_Unreactive" && *it == "Player")
	{
		is_killed = true;
		return true;
	}
	if(type == "Enemy_Unreactive" && *it == "Enemy_Unreactive")
	{
		return false;
	}
	if(type == "Enemy_Unreactive" && *it == "Enemy_Reactive")
	{
		return false;
	}
}

bool Gamerules::Enemy_Reactive_checks(std::string type, std::vector<std::string>::iterator it) {
	/**
	 * Check if the Enemy_Reactive has collided with anything
	 * @param type The type to check with, must be "Enemy_Reactive" for this function to have any effect.
	 * @param it The object to check against.
	 * @return Returns true if Enemy_Reactive does not collide with anything, otherwise returns false
	 */
	if(type == "Enemy_Reactive" && *it == "Player")
	{
		is_killed = true;
		return true;
	}
	if(type == "Enemy_Reactive" && *it == "Enemy_Unreactive")
	{
		return false;
	}
	if(type == "Enemy_Reactive" && *it == "Enemy_Reactive")
	{
		return false;
	}
	if(type == "Enemy_Reactive" && *it == "Wall")
	{
		return false;
	}
}

bool Gamerules::can_move(std::string type, std::vector<std::string> colliding_objects_type) {
	/**
	 * Check if the first parameters collides with anything in the provided container.
	 * @param type The type to check with.
	 * @param it The objects to check against.
	 * @return Returns true if type does not collide with anything, otherwise returns false
	 */


	std::vector<std::string>::iterator it;
	// Declear a bool that controlls if the type can move or not.
	bool can_move_to_next_place = true;
	// Check everyobject in the container if they collides with type.
	for( it=colliding_objects_type.begin(); it != colliding_objects_type.end(); it++)
	{
		// If any object collides with type, set the bool to false.
		can_move_to_next_place = Player_checks(type, it);
		can_move_to_next_place = Enemy_Unreactive_checks(type, it);
		can_move_to_next_place = Enemy_Reactive_checks(type, it);

	}
	// Return the bool variable that check if their has been an illegal collision.
	return can_move_to_next_place;
}
