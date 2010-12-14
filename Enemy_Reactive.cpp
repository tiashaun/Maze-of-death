/*
 * Player.cpp
 *
 *  Created on: Nov 25, 2010
 *      Author: proxz
 */

#include "Enemy_Reactive.h"
#include "Game.h"
#include "Player.h"

#include <vector>
#include <cmath>

const int Enemy_Reactive_WIDTH = 35;				// Enemy's SDL_rectangle width
const int Enemy_Reactive_HEIGTH = 35;				// Enemy's SDL_rectangle heigth
const int Enemy_Reactive_MAXIMUM_X_SPEED = 40;		// Enemy's SDL_rectangle width
const int Enemy_Reactive_MAXIMUM_Y_SPEED = 40;		// Enemy's SDL_rectangle heigth

const uint Enemy_Reactive_FOLLOW_TIME_SECONDS = 5;	// Amount of time to chase the player, after it have exited it's attack area


Enemy_Reactive::Enemy_Reactive(Level& level, int x_start_coordinate, int y_start_coordinate, float speed, std::vector<Node*> *nodes)
	: Enemy(level, speed, nodes), reference_to_player(get_level().get_player()), gamerules(get_level().get_gamerules()) {
	/**
	 * Constructor for Enemy_Reactive.
	 * @param level The level object that the object will belong to
	 * @param x_start_coordinate The x position the object should start on
	 * @param y_start_coordinate The y position the object should start on
	 * @param speed The speed that the object will have on the level, provided as a float.
	 * @param nodes The nodes that the enemy can follow, can be provided as an empty vector.
	 * @return An Enemy_Reactive object
	 */

	set_xVelocity(0);								// Default values
	set_yVelocity(0);								// Default values
	set_type("Enemy_Reactive");						// Type name used to identify this enemy
	set_is_object_movable(true);					// Parameter to detect if the object is a moveable sprite
	following_player = false;						// Object is not following the player when game starts
	box.x = x_start_coordinate;						// Enemy's SDL_Rect, x-coordinate
	box.y = y_start_coordinate;						// Enemy's SDL_Rect, y-coordinate
	box.w = Enemy_Reactive_WIDTH;					// Enemy's SDL_Rect, width
	box.h = Enemy_Reactive_HEIGTH;					// Enemy's SDL_Rect, height
	attack_area_circle.radius = 100;		    	// Attack radius to start chasing player object
	attack_area_circle.x = box.x + (box.w / 2); 	// Center of the circle, x-coordinate
	attack_area_circle.y = box.y + (box.h / 2); 	// Center of the circle, y-coordinate
	image = NULL;									// Initialise the image pointer to null for safety.
}


double Enemy_Reactive::round(double r) {
	/**
	 * Round correct for both positive and negative values.
	 * Does not change the input value
	 * @parameter r double value to be rounded
	 * @return The correct rounded value
	 */

    return (r > 0.0) ? floor(r + 0.5) : ceil(r - 0.5);
}

void Enemy_Reactive::start_following_player() {
	/**
	 * Initiate variables to follow player
	 */
	following_player = true;
	time_followed = 0;
}

void Enemy_Reactive::chase_player() {
	/**
	 * Changes velocity values, so the object moves towards the player
	 */

	// Calculate the velocity needed in x and y to move towards the player
	SDL_Rect* player_rectangle = reference_to_player.get_rect();
	Velocity vel = calculate_velocity(box.x, box.y, player_rectangle->x, player_rectangle->y, this->get_speed());

	// Check that the velocity values are within reasonable range
	bool velocity_x_is_to_big = vel.x > 0 && vel.x < Enemy_Reactive_MAXIMUM_X_SPEED;
	bool velocity_y_is_to_big = vel.y > 0 && vel.y < Enemy_Reactive_MAXIMUM_Y_SPEED;
	bool velocity_x_is_to_small = vel.x<0 && vel.x > Enemy_Reactive_MAXIMUM_Y_SPEED*(-1);
	bool velocity_y_is_to_small = vel.y < 0 && vel.y > Enemy_Reactive_MAXIMUM_Y_SPEED*(-1);

	// If x and y velocity is within range update with the new values
	if(velocity_x_is_to_big || velocity_y_is_to_big || velocity_x_is_to_small || velocity_y_is_to_small)
	{
		set_xVelocity(vel.x);
		set_yVelocity(vel.y);
	}
	else
	{
		// If x and y is not within accepatble range use old values, hence do not update Velocity values.
	}
}

void Enemy_Reactive::stop_chasing_player() {
	/**
	 * Set variables to stop following player
	 */
	following_player = false;
	set_xVelocity(0);
	set_yVelocity(0);
}

void Enemy_Reactive::check_and_set_enemy_state() {
	/**
	 * Handle object movement, follow player if he is close otherwise move to next node
	 */

	// Check if player is close
	SDL_Rect* player_rectangle = reference_to_player.get_rect();
	bool player_is_within_radius = is_within_radius(attack_area_circle, player_rectangle);

	// If player is close and the object is not chasing, start chasing the player.
	if(player_is_within_radius && following_player == false)
	{
		start_following_player();
	}

	// If the player is close by and we are following, continue to chase the player.
	if(player_is_within_radius == true && following_player == true)
	{
		chase_player();
	}
	// If the player moves out of detection range and we are following, contineu chase for a limited amount of time
	else if(following_player == true && player_is_within_radius == false && time_followed <= Enemy_Reactive_FOLLOW_TIME_SECONDS * 10)
	{
		chase_player();
		time_followed += 1;
	}
	// If the enemy escapes and have been away for to long, stop chasing player
	else if(following_player == true && player_is_within_radius == false && time_followed > Enemy_Reactive_FOLLOW_TIME_SECONDS * 10)
	{
		stop_chasing_player();
	}
	// If we are not following player, move to next node.
	else if( following_player == false)
	{
		move_to_target_node();
	}
	else
	{
		// Default behaviour if none of the cases works.
		// Note this is an exception case, one of the if cases should always activate.
		move_to_target_node();
	}
}


void Enemy_Reactive::update() {
	/**
	*  Controlls and update the enemys movement.
	*/

	// Update the detection circle, with enemy's rectangle coordinates
	update_circle(box.x, box.y);
	check_and_set_enemy_state();

	move();

	// Store type of colliding objects
	std::vector<std::string> colliding_objects_type;
	colliding_objects_type = get_level().check_collisions(this);

	// Check if the enemy collide with something it can't collide with.
	if( !colliding_objects_type.empty()
		&&	get_level().get_gamerules().can_move(get_type(), colliding_objects_type ) == false)
	{
		// If it does, take him back to last position
		box.x -= get_xVelocity();
		box.y -= get_yVelocity();
	}
	else
	{
		// He dosn't collide with anything and dosn't need to be moved back.
	}
}

void Enemy_Reactive::show( SDL_Surface* screen) {
	/**
	 * Draw Enemy_Reactive object on screen
	 * @param screen The screen object that the images draws on.
	 */

	// Check is image does not exist
	if( image  == NULL )
	{
		// If it doesn't exist load image.
		image = load_image( "Images/zombie2.bmp" );
	}

	// Draw image on screen object
	apply_surface( box.x, box.y, image, screen );
}



double Enemy_Reactive::distance( int x1, int y1, int x2, int y2 ) {
    /**
     * Return the distance between the two points
     * @param x1 First objects x-coordinate
     * @param y1 First objects y-coordinate
     * @param x2 Second objects x-coordinate
     * @param y2 Second objects y-coordinate
     * @return The distance between the object as a float
     */
    return sqrt( pow( x2 - x1, 2 ) + pow( y2 - y1, 2 ) );
}


void Enemy_Reactive::update_circle(int x, int y) {
	/**
	 *  Updates the enemy's detection circle area.
	 *  @param x The x value of the object
	 *  @param y The y value of the object
	 */
	attack_area_circle.x = box.x + (box.w / 2);
	attack_area_circle.y = box.y + (box.h / 2);
}

bool Enemy_Reactive::is_within_radius(Circle &circle, SDL_Rect* rectangle) {
	/**
	 * Check if rectangle is within circle
	 * @param circle A reference to the detection circle
	 * @param rectangle The object to check against rectangle
	 * @return Returns true if the object is within the detection radius, otherwise return false
	 */

    // Initialise varaibles to hold the closest position of the rectangle that we are cheking against
    int closest_point_x, closest_point_y;

	// Find closest x offset
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

	// Find closest y offset
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

	// If the closest point is inside the circle
	if( distance( circle.x, circle.y, closest_point_x, closest_point_y ) < circle.radius )
	{
		//This box and the circle have collided then we return true
		return true;
	}

    // Otherwise the shapes have not collided then we return false
    return false;
}

Enemy_Reactive::~Enemy_Reactive() {
	// Check if the object has an image
	if(image != NULL)
	{
		// if it has free the memory space.
		SDL_FreeSurface(image);
	}
}
