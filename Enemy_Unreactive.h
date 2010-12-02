/*
 * Enemy_Unreactive.h
 *
 *  Created on: Nov 30, 2010
 *      Author: matol004
 */

#ifndef ENEMY_UNREACTIVE_H_
#define ENEMY_UNREACTIVE_H_
#include "Enemy.h"
#include "Level.h"
#include "Gamerules.h"

class Enemy_Unreactive : public Enemy {
public:
	Enemy_Unreactive(Level& level, Gamerules& gamerules, int x_start_coordinate, int y_start_coordinate, int x_start_velocity, int y_start_velocity, std::vector<int> xNodes, std::vector<int> yNodes);
	virtual ~Enemy_Unreactive();
	void show(SDL_Surface* screen);
	void update();
	void move();
private:
	std::string get_type();
	int x_start_coordinate;
	int x_start_velocity;
	int y_start_coordinate;
	int y_start_velocity;
	int node_counter;
	std::vector<int> xNodes;
	std::vector<int> yNodes;
	Level& level;
	Gamerules& gamerules;
};

#endif /* ENEMY_UNREACTIVE_H_ */
