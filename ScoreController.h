#ifndef SCORECONTROLLER_H
#define SCORECONTROLLER_H

#include <SFML/Graphics.hpp>
#include "ScoreView.h"

class ScoreController {
	bool finished = false;
	ScoreView & view;
	sf::RenderWindow &win;
public:
	explicit ScoreController(ScoreView & v, sf::RenderWindow &w);
	void handleEvent(sf::Event &event);

	// no need to change this
	void draw(sf::RenderWindow & win) { view.draw(win); }
	bool isFinished() const { return finished; }
	bool resetState() { finished = false; return finished; }
};


#endif //SCORECONTROLLER_H
