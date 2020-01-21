#include "stdafx.h"
#include "Snake.h"


Snake::Snake() {
	
	start();
	init = true;
	
}

sf::FloatRect Snake::getSpriteBounds() {
	return snake.at(0).sprite.getGlobalBounds();
	
}

std::vector<StructBody> Snake::getSnake() {
	return snake;
}

bool Snake::getIsDead() {
	return isDead;
}

void Snake::start() {
	if (!texture.loadFromFile("snake.png"))
		printf("An error occured");
	sf::Sprite snakeSprite;
	snakeSprite.setTexture(texture);
	spriteSize = snakeSprite.getGlobalBounds();
	snakeDir = RIGHT;
	StructBody snakeHead = { snakeDir, snakeSprite };
	snake.push_back(snakeHead);
	score = 0;
}

void Snake::grow() {
	sf::Sprite snakeBody;
	snakeBody.setTexture(texture);
	StructBody lastBody = snake.back();
	StructBody newBody = {lastBody.direction, snakeBody};
	sf::Vector2f initialPos;

	const float lastBodyX = lastBody.sprite.getPosition().x;
	const float lastBodyY = lastBody.sprite.getPosition().y;
	const float textureX = lastBody.sprite.getLocalBounds().width  ;
	const float textureY = lastBody.sprite.getLocalBounds().height ;

	if (lastBody.direction == RIGHT) {
		initialPos = sf::Vector2f(lastBodyX - textureX, lastBodyY);
	}
	else if (lastBody.direction == LEFT) {
		initialPos = sf::Vector2f(lastBodyX + textureX , lastBodyY);
	}
	else if (lastBody.direction == UP) {
		initialPos = sf::Vector2f(lastBodyX , lastBodyY - textureY);
	}
	else if (lastBody.direction == DOWN) {
		initialPos = sf::Vector2f(lastBodyX, lastBodyY + textureY);
	}

	newBody.sprite.setPosition(initialPos);
	snake.push_back(newBody);
	score += 50;
}


void Snake::outOfBoundsCheck(sf::RenderWindow &window) {
	
	sf::Sprite* snakeHead = &snake.at(0).sprite;
	const float headX = snake.at(0).sprite.getPosition().x;
	const float headY = snake.at(0).sprite.getPosition().y;

	if ( headX  >= window.getSize().x ) {
		snakeHead->setPosition(0, headY);
	}
	else if (headX <= -1) {
		snakeHead->setPosition(window.getSize().x, headY);

	}
	else if (headY >= window.getSize().y ) {
		snakeHead->setPosition(headX, 0);

	}
	else if (headY <= -1) {
		snakeHead->setPosition(headX, window.getSize().y);

	}
}


void Snake::_draw(sf::RenderWindow &window) {
	if (init == false) {
		for (StructBody snakesBody : snake) {
			window.draw(snakesBody.sprite);
		}
	}
}

void Snake::_update(sf::Time delta, sf::RenderWindow &window) {

	StructBody* snakeHead = &snake.at(0);


	if (init == true) {
		sf::Vector2f initPosition = sf::Vector2f((float)window.getSize().x / 2 , (float)window.getSize().y / 2);
		snakeHead->sprite.setPosition(initPosition);
		init = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && snakeDir != LEFT) {
		snakeDir = RIGHT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && snakeDir != RIGHT) {
		snakeDir = LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && snakeDir != DOWN) {
		snakeDir = UP;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && snakeDir != UP) {
		snakeDir = DOWN;
	}


	outOfBoundsCheck(window);


	const float snakeHeadW = snakeHead->sprite.getLocalBounds().width;
	const float snakeHeadH = snakeHead->sprite.getLocalBounds().height;
	sf::Vector2f savedPosition = snakeHead->sprite.getPosition();
	snakeHead->direction = snakeDir; 
	int newDirection = snakeDir;

	switch (snakeDir) {
		case RIGHT: snakeHead->sprite.move(snakeHeadW, 0);
			break;
		case LEFT: snakeHead->sprite.move(-(snakeHeadW), 0);
			break;
		case UP:   snakeHead->sprite.move(0, -(snakeHeadH));
			break;
		case DOWN: snakeHead->sprite.move(0, snakeHeadH);
			break;
		default:break;

	}

	int oldDirection;

	for (int i = 1; i < snake.size(); i++) {
		StructBody* current = &snake.at(i);
		sf::Vector2f trackPos = snake.at(i).sprite.getPosition();
		oldDirection = snake.at(i).direction;
		current->direction = newDirection;
		current->sprite.setPosition(savedPosition);
		savedPosition = trackPos;
		newDirection = oldDirection;

		if (snakeHead->sprite.getGlobalBounds().intersects(current->sprite.getGlobalBounds())) {
			isDead = true;
		}

	}


}

