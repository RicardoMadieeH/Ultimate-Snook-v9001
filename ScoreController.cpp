#include "ScoreController.h"

ScoreController::ScoreController(ScoreView &v, sf::RenderWindow &w) : view(v), win(w)
{}

void ScoreController::handleEvent(sf::Event &event) {
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Space) {
			finished = true;
		}
	}
}
