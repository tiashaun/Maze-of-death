/*
 * Enemy.cpp
 *
 *  Created on: Nov 30, 2010
 *      Author: matol004
 */

#include "Enemy.h"

#include <cmath>
#include <iostream>

Enemy::Enemy(Level& level) : Moving_Sprite(level) {

}

Enemy::Enemy(Level& level, std::vector<Node*> *nodes) : Moving_Sprite(level) {
	set_nodes(nodes);
	current_target_node = nodes->begin();
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
			std::cerr << "here";
			current_target_node = nodes->begin();
		}
	}
	return *current_target_node;
}

void Enemy::set_nodes(std::vector<Node*> *nodes) {
	this->nodes = nodes;
}

Velocity Enemy::calculate_velocity(int object_x_coordinate, int object_y_coordinate,
		int target_x_coordinate, int target_y_coordinate, int move_speed) {
	/**
	 * Calulate which direction the object should move, to end up at target position
	 *
	 * http://stackoverflow.com/questions/2625021/game-enemy-move-towards-player/2625107#2625107
	 */

	Direction direction;

	//Calculate hypotenuse
	direction.x = target_x_coordinate - object_x_coordinate;
	direction.y = target_y_coordinate - object_y_coordinate;
	float hypotenuse = sqrt(direction.x * direction.x + direction.y * direction.y);

	direction.x /= hypotenuse;
	direction.y /= hypotenuse;

	//Calculate velocity, since it's for both x and y -> direction
	Velocity vel;
	vel.x = round(direction.x) * move_speed;
	vel.y = round(direction.y) * move_speed;

	return vel;
}

Enemy::~Enemy() {

}
