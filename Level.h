/*
 * Level.h
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#ifndef LEVEL_H_
#define LEVEL_H_

#include "Sprite.h"

#include <vector>

class Level {
public:
	Level();
	virtual ~Level();
	void fictious_level();
private:
	std::vector<Sprite*> game_objects;
};

#endif /* LEVEL_H_ */
