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

// Used to set the detection area around the enemy
struct Circle {
	int x,y;
	int radius;
};

// Used to calculate the power of x and y speed of the enemy to correctly go in a straight line towards the player.
struct Direction {
	float x, y;
};

class Enemy_Reactive : public Enemy {
public:
	Enemy_Reactive(Level& level, Gamerules& gamerules, int xCord,int yCord);
	virtual ~Enemy_Reactive();
	void show(SDL_Surface* screen);
	void move();
	void update();
private:
	Player& reference_to_player;		// The player object on the level.
	Gamerules& gamerules;
	bool following_player;				// Is the enemy following the player
	uint followed_for;					// How long the enemy should follow the player after the player has left the attack_area_circle.
	Circle attack_area_circle;			// The enemys detection radius, centered around the enemys image on the map.

	void update_circle(int x, int y);
	void move_towards_player(int enemy_x, int enemy_y, int player_x, int player_y);
	double round(double r);
	void check_for_player();
	double distance( int x1, int y1, int x2, int y2 );
	bool is_within_radius(Circle &circle, SDL_Rect* rectangle);
};

#endif /* ENEMY_REACTIVE_H_ */
