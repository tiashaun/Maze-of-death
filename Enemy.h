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
public:
	Enemy(Level& level);
	Enemy(Level& level, float speed, std::vector<Node*> *nodes);
	virtual ~Enemy();
protected:
	Node* get_target_node();
	void set_nodes(std::vector<Node*> *nodes);
	void move_to_target_node();
private:
	std::vector<Node*> *nodes;
	std::vector<Node*>::iterator current_target_node;
};

#endif /* ENEMY_H_ */
