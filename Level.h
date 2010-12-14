/*
 * Level.h
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#ifndef LEVEL_H_
#define LEVEL_H_

#include "Sprite.h"
#include "Gamerules.h"

class Player;

#include <vector>

class Level {
	/**
	 *  Level holds all the object on the level. Also have functions to drawn and update/move the objects.
	 *  Have functions to check for collisions. Also can create levels.
	 */
public:
	Level(SDL_Surface* screen, Gamerules& start_game_rules, std::string name);
	virtual ~Level();
	void clear_level();
	void level1();
	void level2();
	void fill_level(std::vector<Sprite*> new_game_objects);
	void draw_game_objects();
	bool check_collision( SDL_Rect *A, SDL_Rect *B );
//	std::string get_name();
	std::vector<std::string> check_collisions(Sprite* object_to_check);
	Player& get_player();
	void move_moving_sprites();
	Gamerules& get_gamerules();
private:
	bool line_of_sight(int object_x_coordinate, int object_y_coordinate,
			int target_x_coordinate, int target_y_coordinate, int allowed_distance);
	SDL_Surface* screen;				//<! The screen object that the level draws on
	Gamerules& gamerules;				//<! The gamerules that the level obides to
	std::string name;					//<! The name of the level
	std::vector<Sprite*> game_objects;	//<! The game objects on the map
};

#endif /* LEVEL_H_ */
