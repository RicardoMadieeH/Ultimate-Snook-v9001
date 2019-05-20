#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "IntroController.h"
#include "SnakeController.h"
#include "ScoreController.h"
#include "Snake.h"

class GameManager {
	IntroController &introController;
	SnakeController &snakeController;
	ScoreController &scoreController;
	Snake &body;

	enum GameState {
		INTRO, GAME, SCORE
	} state;

	void updateState();
public:
	GameManager(IntroController &ic, SnakeController &mc, ScoreController &sc, Snake &b);

	void draw(sf::RenderWindow &win);

	void handleEvent(sf::Event &event);
};


#endif //GAMEMANAGER_H
