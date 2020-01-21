#pragma once
#include <SFML/Graphics.hpp>


class Engine {
public: 
	Engine();
	virtual void _draw(sf::RenderWindow &window);
	virtual void _update(sf::Time delta, sf::RenderWindow &window);
};