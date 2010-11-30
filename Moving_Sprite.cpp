/*
 * Moving_Sprite.cpp
 *
 *  Created on: Nov 30, 2010
 *      Author: matol004
 */

#include "Moving_Sprite.h"

Moving_Sprite::Moving_Sprite() {
	// TODO Auto-generated constructor stub

}

Moving_Sprite::~Moving_Sprite() {
}

int Moving_Sprite::get_xVelocity(){
	return x_velocity;
}

int Moving_Sprite::get_yVelocity(){
	return y_velocity;
}

void Moving_Sprite::set_xVelocity(int x_new_vel){
	x_velocity = x_new_vel;
}

void Moving_Sprite::set_yVelocity(int y_new_vel){
	y_velocity = y_new_vel;
}
