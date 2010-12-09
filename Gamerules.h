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
	bool has_been_killed();
	virtual ~Gamerules();
	bool can_move(std::string type, std::vector<std::string> colliding_objects_type);
	void reset_status();
private:
	bool has_player_won;
	bool is_killed;
	bool Player_checks(std::string type, std::vector<std::string>::iterator it);
	bool Enemy_Unreactive_checks(std::string type, std::vector<std::string>::iterator it);
	bool Enemy_Reactive_checks(std::string type, std::vector<std::string>::iterator it);
};

#endif /* GAMERULES_H_ */
