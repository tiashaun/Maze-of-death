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

class Enemy : public Moving_Sprite {
	/**
	 *  This object holds all the functions and variables for the Enemy object.
	 *  Enemy holds function to follow nodes, also helps classify all objects that are enemies if they inherit this class.
	 */
public:
	Enemy(Level& level);
	Enemy(Level& level, float speed, std::vector<Node*> *nodes);
	virtual ~Enemy();
protected:
	Node* get_target_node();
	void set_nodes(std::vector<Node*> *nodes);
	void move_to_target_node();
private:
	std::vector<Node*> *nodes;							//!< A vector with all the waypoint nodes for the object
	std::vector<Node*>::iterator current_target_node;	//!< The current node the object is heading towards
};

#endif /* ENEMY_H_ */
