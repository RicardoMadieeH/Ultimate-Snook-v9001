#ifndef SNAKEVIEW_H
#define SNAKEVIEW_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Snake.h"
#include "Button.h"

class SnakeView {
	Snake &body;
	sf::Font arial;
	sf::Text txt;
	sf::Text score;
	Button scoreValue;

	int points;

	sf::RectangleShape wall;
	sf::RectangleShape board;
	sf::RectangleShape snuk;
public:
	SnakeView(Snake &b);

	void draw(sf::RenderWindow &win);
};




#endif //SNAKEVIEW_H
