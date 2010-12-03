/*
 * Player.cpp
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#include "Enemy_Reactive.h"
#include "Game.h"
#include "Player.h"

#include <iostream>
#include <vector>
#include <cmath>

const int Enemy_Reactive_WIDTH = 40;	// Enemy's SDL_rectangle width
const int Enemy_Reactive_HEIGTH = 40;	// Enemy's SDL_rectangle heigth

const uint Enemy_Reactive_FOLLOW_TIME_SECONDS = 5;	// Amount of time to chase the player, after it have exited it's attack area
const float Enemy_Reactive_SPEED = 1; 				// Number of pixels to move per object update

Enemy_Reactive::Enemy_Reactive(Level& level, Gamerules& gamerules, int x_start_coordinate, int y_start_coordinate, std::vector<Node*> *nodes)
	: Enemy(level, nodes), reference_to_player(get_level().get_player()), gamerules(gamerules)
{
	set_xVelocity(0);
	set_yVelocity(0);
	set_type("Enemy_Reactive");					// Type name used to identify this enemy
	set_is_object_movable(true);				// Parameter, to detect if the object is a moveable sprite
	following_player = false;					// Object is not following the player when game starts
	box.x = x_start_coordinate;					// Enemy's SDL_Rect, x-coordinate
	box.y = y_start_coordinate;					// Enemy's SDL_Rect, y-coordinate
	box.w = Enemy_Reactive_WIDTH;				// Enemy's SDL_Rect, width
	box.h = Enemy_Reactive_HEIGTH;				// Enemy's SDL_Rect, height
	attack_area_circle.radius = 100;		    // Attack radius, to start chasing player object
	attack_area_circle.x = box.x + (box.w / 2); // Center of the circle, x-coordinate
	attack_area_circle.y = box.y + (box.h / 2); // Center of the circle, y-coordinate
}


void Enemy_Reactive::move()
{
	/**
	 * Move enemy according to current velocity values
	 */

	box.x += get_xVelocity();
	box.y += get_yVelocity();

}

double Enemy_Reactive::round(double r)
{
	/**
	 * Round correct for both positive and negative values
	 */

    return (r > 0.0) ? floor(r + 0.5) : ceil(r - 0.5);
}

void Enemy_Reactive::check_for_player()
{
	/*
	 *
	 */

	SDL_Rect* player_rectangle = reference_to_player.get_rect();

	bool player_is_within_radius = is_within_radius(attack_area_circle, player_rectangle);

	//Initiate variables to follow player, if player is within range
	if(player_is_within_radius && following_player == false)
	{
		following_player = true;
		followed_for = 0;
	}

	if(player_is_within_radius == true && following_player == true)
	{
		Velocity vel = calculate_velocity(box.x, box.y, player_rectangle->x, player_rectangle->y, Enemy_Reactive_SPEED);
		set_xVelocity(vel.x);
		set_yVelocity(vel.y);
	}
	else if(following_player == true && player_is_within_radius == false && followed_for <= Enemy_Reactive_FOLLOW_TIME_SECONDS * 50)
	{
		Velocity vel = calculate_velocity(box.x, box.y, player_rectangle->x, player_rectangle->y, Enemy_Reactive_SPEED);
		set_xVelocity(vel.x);
		set_yVelocity(vel.y);
		followed_for += 1;
	}
	else if(following_player == true && player_is_within_radius == false)
	{
		following_player = false;
		set_xVelocity(0);
		set_yVelocity(0);
	}
}


void Enemy_Reactive::update()
{
	/*
	*  Move object to new position and check if it's not colliding with any objects it "can't"
	*  if not, move him back to old position
	*/

	update_circle(box.x, box.y); 	//Update the detection circle, with enemy's rectangle coordinates
	check_for_player();

	if( following_player == false)
	{
		Node* node = get_target_node();
		//std::cerr <<
		Velocity vel = calculate_velocity(box.x, box.y, node->x, node->y, Enemy_Reactive_SPEED);
		set_xVelocity(vel.x);
		set_yVelocity(vel.y);
	}


	//Move to new position
	move();

	std::vector<std::string> colliding_objects_type; //Store type of colliding objects
	colliding_objects_type = get_level().check_collisions(this);

	// Check if the enemy collide with something it can't collide with.
	if( get_level().get_gamerules().can_move(get_type(), colliding_objects_type ) == false )
	{
		// If it does, take him back to last position
		box.x -= get_xVelocity();
		box.y -= get_yVelocity();
	}
}

void Enemy_Reactive::show( SDL_Surface* screen)
{
	/*
	 * Draw Enemy_Reactive object on screen
	 * @param screen
	 */
	write_to_screen(screen, "Images/Player.jpg", box.x, box.y);
}



double Enemy_Reactive::distance( int x1, int y1, int x2, int y2 )
{
    /*
     * Return the distance between the two points
     */
    return sqrt( pow( x2 - x1, 2 ) + pow( y2 - y1, 2 ) );
}


void Enemy_Reactive::update_circle(int x, int y)
{
	/**
	 *  Updates the enemy's detection circle area.
	 */
	attack_area_circle.x = box.x + (box.w / 2);
	attack_area_circle.y = box.y + (box.h / 2);
}

bool Enemy_Reactive::is_within_radius(Circle &circle, SDL_Rect* rectangle)
{
	/**
	 * Check if rectangle is within circle
	 */

    //Closest point on collision box
    int closest_point_x, closest_point_y;

	//Find closest x offset
	if( circle.x < rectangle->x )
	{
		closest_point_x = rectangle->x;
	}
	else if( circle.x > rectangle->x + rectangle->w )
	{
		closest_point_x = rectangle->x + rectangle->w;
	}
	else
	{
		closest_point_x = circle.x;
	}

	//Find closest y offset
	if( circle.y < rectangle->y )
	{
		closest_point_y = rectangle->y;
	}
	else if( circle.y > rectangle->y + rectangle->h )
	{
		closest_point_y = rectangle->y + rectangle->h;
	}
	else
	{
		closest_point_y = circle.y;
	}

	//If the closest point is inside the circle
	if( distance( circle.x, circle.y, closest_point_x, closest_point_y ) < circle.radius )
	{
		//This box and the circle have collided
		return true;
	}

    //If the shapes have not collided
    return false;
}

Enemy_Reactive::~Enemy_Reactive() {

}
