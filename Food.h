#pragma once
#include "Entity.h"
#include "StructBody.h"

class Food : public Entity {
public: 
	Food();

	void _draw(sf::RenderWindow& window);
	void _update(sf::Time delta, sf::RenderWindow& window);
	void setSpawnPoints(std::vector<StructBody> spawnPoints);
	void start();
	void setIsDead(bool isDead);
	sf::FloatRect getSpriteBounds();

private:
	std::vector<StructBody> spawnPoints; 
	void spawn();
	bool check_body(sf::Vector2f pos);
	bool isDead;
	sf::Texture texture;
	sf::FloatRect spriteSize;
	sf::Sprite sprite; 
};