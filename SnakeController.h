#ifndef SNAKECONTROLLER_H
#define SNAKECONTROLLER_H

#include <SFML/Graphics.hpp>
#include "SnakeView.h"

class SnakeController {
	bool finished = false;

	SnakeView & view;
	Snake &body;
	// ... & model;
	sf::RenderWindow &win;
	sf::Clock clk;
	sf::Time time;
public:
	explicit SnakeController(SnakeView & v, sf::RenderWindow &w, Snake &b);
public:
	void handleEvent(sf::Event &event);

	// no need to change this
	void draw(sf::RenderWindow & win) { view.draw(win); }
	bool isFinished() const { return finished; }
};



#endif //SNAKECONTROLLER_H
