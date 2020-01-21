#include "Game.h"
#include "stdafx.h"

Game::Game() {}

void Game::run() {
	
	sf::RenderWindow window(sf::VideoMode(256, 256), "Snake Game");
	window.setFramerateLimit(15);
	currentState = playing; 
	snake = new Snake();
	food = new Food();
	std::vector<Entity*> entityList;
	
	sf::Clock clock;
	sf::Time elapsed = clock.restart();
	while (window.isOpen()) {
		sf::Event evnt;
		sf::Time elapsed = clock.restart();
		if (currentState = playing) {
			_update(elapsed, window);
		}
		while (window.pollEvent(evnt)) {
			switch (evnt.type) {
			case(sf::Event::Closed):
				window.close();
			case(sf::Event::KeyPressed):
				if (evnt.key.code == sf::Keyboard::Space)
					currentState == playing;
			}
		}
		window.clear();
		_draw(window);
		window.display();
	}
} 


void Game::_draw(sf::RenderWindow &window) {
	snake->_draw(window);
	food->_draw(window);
}

void Game::_update(sf::Time delta, sf::RenderWindow &window) {
	snake->_update(delta, window);
	std::vector<sf::Vector2f> positions;
	if (snake->getSpriteBounds().intersects(food->getSpriteBounds())) {
		food->setIsDead(true);
		std::vector<StructBody> snakesBody = snake->getSnake();
		snake->grow();
		food->setSpawnPoints(snakesBody);
	}
	if (snake->getIsDead() == true) {
		snake = new Snake();
	}
}


