#pragma once
#include "Engine.h"
#include <string>

class Entity: public Engine {
public: 
	Entity();
	void _draw(sf::RenderWindow &window);
    void _update(sf::Time delta, sf::RenderWindow &window);
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::FloatRect spriteSize; 
};