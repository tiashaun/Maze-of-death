/*
 * Enemy.cpp
 *
 *  Created on: Nov 30, 2010
 *      Author: matol004
 */

#include "Enemy.h"
#include <iostream>

Enemy::Enemy(Level& level) : Moving_Sprite(level,1) {
	/**
	 * Constructor for the abstract class Enemy, passes a default value for speed which is 1.
	 * Does not handle nodes.
	 * @param level Contains the level the object is on, this is passed to Moving_Sprite.s
	 * @warning Not meant to be instantiated. This constructor should only be used if you have no speed or node values.
	 */
}

Enemy::Enemy(Level& level, float speed, std::vector<Node*> *nodes) : Moving_Sprite(level, speed) {
	/**
	 * Main constructor for the abstract class Enemy.
	 * @param level Contains the level the object is on, this is passed to Moving_Sprite.
	 * @param speed The speed the object will have.
	 * @param nodes The node container the object should use.
	 * @warning Not meant to be instantiated.
	 */
	set_nodes(nodes);

	// Check if the nodes container is empty.
	if(nodes->empty() == false)
	{
		// If not empty set the current node to the first in the node container.
		current_target_node = nodes->begin();
	}
	else
	{
		// If empty set the object nodes to null.
		set_nodes(0);
	}

}



Node* Enemy::get_target_node() {
	/*
	 * Return target node, if already at target - return next node
	 * @return Returns the node the object is heading towards
	 */

	// Check if object is at current_target_node
	if( (*current_target_node)->x == box.x && (*current_target_node)->y == box.y)
	{
		// If it is, return the next node
		current_target_node++;
		// If current node is the last in the node container, return the first node in the node container
		if(current_target_node == nodes->end() )
		{
			current_target_node = nodes->begin();
		}
	}
	return *current_target_node;
}


void Enemy::move_to_target_node() {
	/**
	 * Sets the objects x and y velocity so the objects is heading towards the node
	 *
	 */
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
	/**
	 * Set the objects node container to the in parameter.
	 * @param nodes The node container that is to be used by the object.
	 */
	this->nodes = nodes;
}

Enemy::~Enemy() {
	/**
	 * Frees the memory of the node container, deletes and sets all pointers in the container to null.
	 */
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
