#include "SnakeController.h"

SnakeController::SnakeController(SnakeView &v, sf::RenderWindow &w, Snake &b) :view(v), win(w), body(b)
{}

void SnakeController::handleEvent(sf::Event &event) {
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Up) {
			body.turnUp();
			
		}
		else if (event.key.code == sf::Keyboard::Left) {
			body.turnLeft();
		}
		else if (event.key.code == sf::Keyboard::Down) {
			body.turnDown();
		}
		else if (event.key.code == sf::Keyboard::Right) {
			body.turnRight();
		}
	}
	if (body.getStateOfGame() != RUNNING) {
		if (event.type == sf::Event::KeyPressed) {
			finished = true;
		}
	}
}
