#pragma once
#include <SFML/Graphics.hpp>

class Button {
public:
	Button(sf::Vector2f position);
	void _draw(sf::RenderWindow& window);
	void _update(sf::Time delta, sf::RenderWindow &window);
	void init();

private:
	int height;
	int width;
	sf::Vector2f position;
	sf::Sprite sprite;
	sf::Texture textureDefault;
	sf::Texture textureOnClick;
};