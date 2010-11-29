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
	static bool can_move(std::string type, std::vector<std::string> colliding_objects_type);
};

#endif /* GAMERULES_H_ */
