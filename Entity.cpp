#include "Entity.h"
#include "stdafx.h"


Entity::Entity() {
	spriteSize = sprite.getGlobalBounds();
	sprite.setOrigin(spriteSize.width / 2, spriteSize.height / 2);
}


void Entity::_draw(sf::RenderWindow &window){
	window.draw(sprite);
}	

void Entity::_update(sf::Time delta, sf::RenderWindow &window) {}

