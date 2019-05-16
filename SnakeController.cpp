#include "SnakeController.h"

SnakeController::SnakeController(SnakeView &v, sf::RenderWindow &w) :view(v), win(w)
{}

void SnakeController::handleEvent(sf::Event &event) {
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Space) {
			finished = true;
		}
	}
}
