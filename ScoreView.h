#ifndef SCOREVIEW_H
#define SCOREVIEW_H

#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Snake.h"
#include "SnakeView.h"
#include <iostream>
#include <sstream>
#include <fstream>

class ScoreView {
	sf::Font font;

	int endScore;
	int bestScore;

	Snake &body;

	std::ofstream highscore;

	std::string scoreString;
	std::string highscoreString;

	sf::Text yS;
	sf::Text hS;
	sf::Text yourScore;
	sf::Text highScore;

	Button koniec;

public:

	Button tryAgain;
	Button exit;

	ScoreView(Snake &b);

	void setScore();

	void draw(sf::RenderWindow &win);
};


#endif //SCOREVIEW_H
