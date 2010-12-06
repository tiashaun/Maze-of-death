#include "Game.h"
#include <exception>
#include <iostream>


int main() {
	try
	{
		Game game;
		game.run();
		return 0;
	}
	catch(char const* p_string)
	{
		std::cerr << "Exception: " << p_string << std::endl;
	}

}
