/*
 * Enemy.cpp
 *
 *  Created on: Nov 30, 2010
 *      Author: matol004
 */

#include "Enemy.h"
#include <iostream>

Enemy::Enemy(Level& level) : Moving_Sprite(level,1) {
	std::cerr << "konstruktor";
}

Enemy::Enemy(Level& level, float speed, std::vector<Node*> *nodes) : Moving_Sprite(level, speed) {
	set_nodes(nodes);

	if(nodes->empty() == false)
	{
		current_target_node = nodes->begin();
	}
	else
	{
		set_nodes(0);
	}

}



Node* Enemy::get_target_node() {
	/*
	 * Return target node, if already at target - return next node
	 */

	//Object at current_target_node

	if( (*current_target_node)->x == box.x && (*current_target_node)->y == box.y)
	{
		current_target_node++;
		if(current_target_node == nodes->end() )
		{
			current_target_node = nodes->begin();
		}
	}
	return *current_target_node;
}


void Enemy::move_to_target_node() {
	// Check if pointer to node vector is valid
	if(nodes != 0)
	{
		// If node was valid update the enemyes velocity to reach the node
		Node* node = get_target_node();
		Velocity vel = calculate_velocity(box.x, box.y, node->x, node->y, this->get_speed());
		set_xVelocity(vel.x);
		set_yVelocity(vel.y);
	}
	// If node is null set speed to zero.
	else
	{
		set_xVelocity(0);
		set_yVelocity(0);
	}
}

void Enemy::set_nodes(std::vector<Node*> *nodes) {
	this->nodes = nodes;
}

Enemy::~Enemy() {
	std::vector<Node*>::iterator it;
	if(!nodes==0)
	{
		for(it = nodes->begin(); it != nodes->end(); it++)
		{
			delete *it;
			*it = NULL;
		}
	}

}
