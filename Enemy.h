/*
 * Enemy.h
 *
 *  Created on: Nov 30, 2010
 *      Author: matol004
 */

#ifndef ENEMY_H_
#define ENEMY_H_
#include "Moving_Sprite.h"

class Enemy : public Moving_Sprite {
public:
	Enemy();
	virtual ~Enemy();
	virtual void move() = 0;
};

#endif /* ENEMY_H_ */
