/*
 * Enemy_reactive.h
 *
 *  Created on: Nov 30, 2010
 *      Author: matol004
 */

#ifndef ENEMY_REACTIVE_H_
#define ENEMY_REACTIVE_H_
#include "Enemy.h"
#include "Level.h"
#include "Gamerules.h"
class Gamerules;


struct Circle {
	/**
	 * Used to set the detection area around the enemy
	 */
	int x,y;	// x and y coordinates of the circle
	int radius; // The radius of the circle around the x and y coordinates
};

class Enemy_Reactive : public Enemy {
	/**
	 *  This object holds all the functions and variables for the Enemy_Reactive object.
	 */
public:
	Enemy_Reactive(Level& level, int x_start_coordinate, int y_start_coordinate, float speed, std::vector<Node*> *nodes);
	virtual ~Enemy_Reactive();
	void show(SDL_Surface* screen);
	void update();
private:
	Player& reference_to_player;		//!< The player object on the level.
	Gamerules& gamerules;				//!< The gamerules object that applies to the level
	bool following_player;				//!< Is the enemy following the player
	uint time_followed;					//!< How long the enemy should follow the player after the player has left the attack_area_circle.
	Circle attack_area_circle;			//!< The enemys detection radius, centered around the enemys image on the map.
	SDL_Surface* image;					//!< Image of the Enemy_Reactive

	void update_circle(int x, int y);
	double round(double r);
	void check_and_set_enemy_state();
	double distance( int x1, int y1, int x2, int y2 );
	bool is_within_radius(Circle &circle, SDL_Rect* rectangle);

	void start_following_player();
	void chase_player();
	void stop_chasing_player();
};

#endif /* ENEMY_REACTIVE_H_ */
