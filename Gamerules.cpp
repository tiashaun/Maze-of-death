/*
 * Gamerules.cpp
 *
 *  Created on: Nov 29, 2010
 *      Author: proxz
 */

#include "Gamerules.h"
#include <iostream>

bool Gamerules::can_move(std::string type, std::vector<std::string> colliding_objects_type)
{
	/*
	 *
	 */

	std::vector<std::string>::iterator it;

	for( it=colliding_objects_type.begin(); it != colliding_objects_type.end(); it++)
	{
		if(type == "Player" && *it == "Wall")
		{
			return false;
		}

		if(type == "Enemy_Unreactive" && *it == "Wall")
		{
			return false;
		}
		if( (type == "Enemy_Unreactive" && *it == "Player") || (type == "Player" && *it == "Enemy_Unreactive"))
		{
			std::cerr << "dieee";
		}
		if( (type == "Enemy_Reactive" && *it == "Player") || (type == "Player" && *it == "Enemy_Reactive"))
		{
			std::cerr << "dieee";
		}
		if( (type == "Enemy_Reactive" && *it == "Player") || (type == "Player" && *it == "Enemy_Reactive"))
		{
			std::cerr << "dieee";
		}
	}
	return true;
}
