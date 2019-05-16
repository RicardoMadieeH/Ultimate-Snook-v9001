#ifndef SNAKEVIEW_H
#define SNAKEVIEW_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Snake.h"

class SnakeView {
	Snake &body;
	sf::Font arial;
	sf::Text txt;
	sf::Text score;

	sf::Texture wallTexture;


	sf::RectangleShape wall;
	sf::RectangleShape board;
public:
	SnakeView(Snake &b);

	void draw(sf::RenderWindow &win);
};




#endif //SNAKEVIEW_H
