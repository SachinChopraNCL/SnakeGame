#include "stdafx.h"
#include "Button.h"

Button::Button(sf::Vector2f position) {
	this->position = position;
	init();
}


void Button::init() {
	if (!textureDefault.loadFromFile("buttonDefault.png"))
		printf("An error occured");
	if (!textureOnClick.loadFromFile("buttonOnClick.png"))
		printf("An error occured");
	sprite.setTexture(textureDefault);
	sprite.setPosition(position);
}

void Button::_update(sf::Time delta, sf::RenderWindow& window) {

}

void Button::_draw(sf::RenderWindow &window) {

}
