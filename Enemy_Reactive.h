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

struct Circle {
	int x,y;
	int radius;
};

struct Direction {
	float x, y;
};

class Enemy_Reactive : public Enemy {
public:
	Enemy_Reactive(Level& level,int xCord,int yCord);
	virtual ~Enemy_Reactive();
	void show(SDL_Surface* screen);
	void move();
	void update();
private:
	void update_circle(int x, int y);
	std::string get_type();
	int x_velocity;
	int y_velocity;
	Level& level;
	Player& reference_to_player;
	Circle attack_area_circle;
	bool following_player;
	uint followed_for;

	void move_towards_player(int enemy_x, int enemy_y, int player_x, int player_y);
	double round(double r);
	void check_for_player();

	double distance( int x1, int y1, int x2, int y2 );
	bool is_within_radius(Circle &circle, SDL_Rect* rectangle);
};

#endif /* ENEMY_REACTIVE_H_ */
