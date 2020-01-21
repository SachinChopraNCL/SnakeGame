#include "stdafx.h"
#include "Food.h"

Food::Food() {
	start();
}

void Food::start() {
	if (!texture.loadFromFile("food.png"))
		printf("an error occured");
	sprite.setTexture(texture);
	spriteSize = sprite.getGlobalBounds();
	sprite.setOrigin(spriteSize.width / 2, spriteSize.height / 2);
	isDead = true;
}

void Food::setIsDead(bool isDead) {
	this->isDead = isDead;
}

sf::FloatRect Food::getSpriteBounds() {
	return sprite.getGlobalBounds();;
}

void Food::setSpawnPoints(std::vector<StructBody> spawnPoints) {
	this->spawnPoints = spawnPoints;
}

void Food::_draw(sf::RenderWindow& window) {
	if (isDead == true) {
		spawn();
		isDead = false;
	}
	window.draw(sprite);
}

void Food::_update(sf::Time delta, sf::RenderWindow& window) {

}

void Food::spawn() {
	srand(time(NULL));
	sf::Vector2f pos;
	int spriteX;
	int spriteY;
	do {
		spriteX = rand() % 256 + 1;
		spriteY = rand() % 256 + 1;
		pos = sf::Vector2f(spriteX, spriteY);
	} while (check_body(pos) == true);
	sprite.setPosition(spriteX, spriteY);
}

bool Food::check_body(sf::Vector2f pos) {
	for (int i = 0; i < spawnPoints.size(); i++) {
		if (spawnPoints.at(i).sprite.getGlobalBounds().contains(pos)) {
			return true;
		}
	}
	return false;
}