/*
 * Level.h
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#ifndef LEVEL_H_
#define LEVEL_H_

#include "Sprite.h"

class Player;

#include <vector>

class Level {
public:
	Level(SDL_Surface* destination);
	virtual ~Level();
	void fictious_level();
	void draw_game_objects();
	bool check_collision( SDL_Rect *A, SDL_Rect *B );
	std::vector<std::string> check_collisions(Sprite* object_to_check);
	Player& get_player();
	void move_moving_sprites();
private:
	std::vector<Sprite*> game_objects;
	SDL_Surface* destination;
};

#endif /* LEVEL_H_ */
