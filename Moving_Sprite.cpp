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

int Moving_Sprite::get_xVel(){
	return xVel;
}

int Moving_Sprite::get_yVel(){
	return yVel;
}

void Moving_Sprite::set_xVel(int x_new_vel){
	xVel = x_new_vel;
}

void Moving_Sprite::set_yVel(int y_new_vel){
	yVel = y_new_vel;
}
