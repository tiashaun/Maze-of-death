/*
 * Enemy.h
 *
 *  Created on: Nov 30, 2010
 *      Author: matol004
 */

#ifndef ENEMY_H_
#define ENEMY_H_
#include "Moving_Sprite.h"

struct Nodes {
	int x,y;
};

class Enemy : public Moving_Sprite {
public:
	Enemy(Level& level);
	virtual ~Enemy();
};

#endif /* ENEMY_H_ */
