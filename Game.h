#pragma once
#include "Engine.h"
#include "Snake.h"
#include "Food.h"

class Game: public Engine {
public:
	Game();
	void run();
	
private:
	void _draw(sf::RenderWindow &window);
	void _update(sf::Time delta, sf::RenderWindow &window);
	enum  state {menu, playing};
	state currentState;
	Snake* snake;
	Food* food;
};