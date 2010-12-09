/*
 * Gamerules.cpp
 *
 *  Created on: Nov 29, 2010
 *      Author: proxz
 */

#include "Gamerules.h"
#include <iostream>

Gamerules::Gamerules() {
	has_player_won = false;
	is_killed = false;
}

Gamerules::~Gamerules() {

}

bool Gamerules::has_won() {
	return has_player_won;
}

bool Gamerules::has_been_killed() {
	return is_killed;
}

void Gamerules::reset_status() {
	has_player_won = false;
}

bool Gamerules::Player_checks(std::string type, std::vector<std::string>::iterator it) {
	if(type == "Player" && *it == "Wall")
	{
		std::cerr << "Vägg!";
		return false;
	}
	if(type == "Player" && *it == "Enemy_Unreactive")
	{
		std::cerr << "dieee";
		is_killed = true;
		return true;
	}
	if(type == "Player" && *it == "Enemy_Reactive")
	{
		std::cerr << "dieee";
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
	if(type == "Enemy_Unreactive" && *it == "Wall")
	{
		return false;
	}
	if(type == "Enemy_Unreactive" && *it == "Player")
	{
		std::cerr << "dieee";
		is_killed = true;
		return true;
	}
	if(type == "Enemy_Unreactive" && *it == "Enemy_Unreactive")
	{
		return false;
	}
	if(type == "Enemy_Unreactive" && *it == "Enemy_Reactive")
	{
		std::cerr << " FLYTTA PÅ DIG DIN JÄVEL JAG SKA DÖDA ";;
		return false;
	}
}

bool Gamerules::Enemy_Reactive_checks(std::string type, std::vector<std::string>::iterator it) {
	if(type == "Enemy_Reactive" && *it == "Player")
	{
		std::cerr << "dieee";
		is_killed = true;
		return true;
	}
	if(type == "Enemy_Reactive" && *it == "Enemy_Unreactive")
	{
		std::cerr << " FLYTTA PÅ DIG DIN JÄVEL JAG SKA DÖDA ";
		return false;
	}
	if(type == "Enemy_Reactive" && *it == "Enemy_Reactive")
	{
		std::cerr << " FLYTTA PÅ DIG DIN JÄVEL JAG SKA DÖDA ";
		return false;
	}
	if(type == "Enemy_Reactive" && *it == "Wall")
	{
		return false;
	}
}

bool Gamerules::can_move(std::string type, std::vector<std::string> colliding_objects_type) {


	std::vector<std::string>::iterator it;
	bool can_move_to_next_place = true;

	for( it=colliding_objects_type.begin(); it != colliding_objects_type.end(); it++)
	{

		can_move_to_next_place = Player_checks(type, it);
		can_move_to_next_place = Enemy_Unreactive_checks(type, it);
		can_move_to_next_place = Enemy_Reactive_checks(type, it);

	}
	return can_move_to_next_place;
}
