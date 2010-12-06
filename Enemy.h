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
	Enemy(Level& level, float speed, std::vector<Node*> *nodes);
	virtual ~Enemy();
	Velocity calculate_velocity(int object_x_coordinate, int object_y_coordinate,
			int target_x_coordinate, int target_y_coordinate, int move_speed);
	Node* get_target_node();
	float get_speed();
	void set_nodes(std::vector<Node*> *nodes);
	void move_to_target_node();
private:
	const float speed; 					// Number of pixels to move per object update
	std::vector<Node*> *nodes;
	std::vector<Node*>::iterator current_target_node;
};

#endif /* ENEMY_H_ */
