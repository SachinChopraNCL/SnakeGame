#pragma once
#include "Entity.h"
#include "StructBody.h"
class Snake : public Entity {
public:
	Snake();
	
	void _draw(sf::RenderWindow &window);
	void _update(sf::Time delta, sf::RenderWindow &window);
	void grow();
	void start();	
	void outOfBoundsCheck(sf::RenderWindow &window);
	sf::FloatRect getSpriteBounds();
	std::vector<StructBody> getSnake();
	bool getIsDead();


private:
	sf::Texture texture;
	sf::FloatRect spriteSize;
	enum direction { UP, DOWN, LEFT, RIGHT };
	direction snakeDir;
	std::vector<StructBody> snake;
	bool isDead;
	bool init;
	int score;
	
};