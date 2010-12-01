/*
 * Gamerules.h
 *
 *  Created on: Nov 29, 2010
 *      Author: proxz
 */

#ifndef GAMERULES_H_
#define GAMERULES_H_

#include <string>
#include <vector>

class Gamerules {
public:
	Gamerules();
	bool has_won();
	virtual ~Gamerules();
	bool can_move(std::string type, std::vector<std::string> colliding_objects_type);
private:
	bool has_player_won;
};

#endif /* GAMERULES_H_ */
