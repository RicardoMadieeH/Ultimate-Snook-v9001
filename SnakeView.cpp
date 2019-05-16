#include "SnakeView.h"

SnakeView::SnakeView(Snake &b) :body(b) {
	if (!arial.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-B.ttf")) {
		if (!arial.loadFromFile("C:\\Windows\\Fonts\\arial.ttf")) {
			abort();
		}
	}

	wall.setSize(sf::Vector2f(1280, 720));
	wall.setPosition(sf::Vector2f(0, 0));


	board.setFillColor(sf::Color(0,255,0));
	board.setSize(sf::Vector2f(1280, 720));
	board.setPosition(sf::Vector2f(0, 0));
	

	txt.setFont(arial);
	txt.setFillColor(sf::Color(150, 150, 150));
	
}

void SnakeView::draw(sf::RenderWindow &win) {
	
	win.draw(board);

}


