#include "GameManager.h"

GameManager::GameManager(IntroController &ic, SnakeController &mc, ScoreController &sc, Snake &b)
	: introController(ic), snakeController(mc), scoreController(sc), body(b)
{

	state = INTRO;
}

void GameManager::updateState() {
	switch (state) {
	case INTRO:
		if (introController.isFinished()) {
			body.startSnake();
			state = GAME;
		}
		break;
	case GAME:
		if (snakeController.isFinished())
			state = SCORE;
		break;
	case SCORE:
		if (scoreController.isFinished()) {
			introController.resetState();
			snakeController.resetState();
			scoreController.resetState();
			state = INTRO;
		}
		break;
	}
}

void GameManager::handleEvent(sf::Event &event)
{
	switch (state) {
	case INTRO:
		introController.handleEvent(event);
		break;
	case GAME:
		snakeController.handleEvent(event);
		break;
	case SCORE:
		scoreController.handleEvent(event);
		break;
	}
	updateState();
}

void GameManager::draw(sf::RenderWindow &win) {
	// updateState();
	switch (state) {
	case INTRO:
		introController.draw(win);
		break;
	case GAME:
		snakeController.draw(win);
		break;
	case SCORE:
		scoreController.draw(win);
		break;
	}
}
