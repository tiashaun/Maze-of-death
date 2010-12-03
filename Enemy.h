/*
 * Enemy.h
 *
 *  Created on: Nov 30, 2010
 *      Author: matol004
 */

#ifndef ENEMY_H_
#define ENEMY_H_
#include "Moving_Sprite.h"

#include <vector>

struct Node {
	int x,y;
public:
	Node(int x,int y): x(x), y(y) {

	}
};

struct Direction {
	float x, y;
};

struct Velocity {
	int x, y;
};

class Enemy : public Moving_Sprite {
public:
	Enemy(Level& level);
	Enemy(Level& level, std::vector<Node*> *nodes);
	virtual ~Enemy();
	Node* get_target_node();
	Velocity calculate_velocity(int object_x_coordinate, int object_y_coordinate,
			int target_x_coordinate, int target_y_coordinate, int move_speed);
	void set_nodes(std::vector<Node*> *nodes);
private:

	std::vector<Node*> *nodes;
	std::vector<Node*>::iterator current_target_node;
};

#endif /* ENEMY_H_ */
