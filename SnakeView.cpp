#include "SnakeView.h"

SnakeView::SnakeView(Snake &b) :body(b) {
	if (!arial.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-B.ttf")) {
		if (!arial.loadFromFile("C:\\Windows\\Fonts\\arial.ttf")) {
			abort();
		}
	}

	//Wall settings//
	wall.setFillColor(sf::Color(204, 127, 86));
	wall.setSize(sf::Vector2f(1280, 720));
	wall.setPosition(sf::Vector2f(0, 0));

	//Board settings//
	board.setFillColor(sf::Color(163, 204, 86));
	board.setSize(sf::Vector2f(1080, 520));
	board.setPosition(sf::Vector2f(100, 100));
	
	//Score text settings//
	txt.setFont(arial);
	txt.setFillColor(sf::Color::Black);
	txt.setCharacterSize(50);
	txt.setString("SCORE:");
	txt.setPosition(sf::Vector2f(100,10));

	//Score Value settings//
	scoreValue.sizeSet(sf::Vector2f(0, 0));
	scoreValue.setFont(arial);
	scoreValue.setBackColor(sf::Color(204, 127, 86));
	scoreValue.setTextColor(sf::Color::Black);
	scoreValue.setTextPosition(sf::Vector2f(300, 10));
	scoreValue.setTextSize(50);
	
	//Snake Body Tiles settings//
	snuk.setFillColor(sf::Color(85, 102, 191));
	snuk.setSize(sf::Vector2f(36, 26)); // (1080/30)=36 // (520/20)=26 // Rozmiar wyliczony na podstawie zalozenia ze plansza ma wymiar 30x20 pol//
	snuk.setOutlineThickness(1);
	snuk.setOutlineColor(sf::Color::Black);


}

void SnakeView::draw(sf::RenderWindow &win) {

	win.draw(wall);
	win.draw(board);
	win.draw(txt);

	//for (int p = body.getLength(); p >= 0; p--) {
	//	for (int i = 100; i <= 1080; i = i + i * 36) {
	//		for (int j = 100; j <= 520; j = j + j * 26) {
	//			snuk.setPosition(sf::Vector2f(body[p].getX()*i, body[p].getY()*j))
	//		}
	//	}
	//}

	//for (int i = 0; i <= body.getLength(); i++) {
	//	snuk.setPosition(sf::Vector2f(body.body.back()->getX() * 35, body.body.back()->getY() * 25));
	//	win.draw(snuk);
	//}
	
	points = body.getLength() - 2;
	scoreValue.setTextString(std::to_string(points), 50);
	scoreValue.drawTo(win);
	
	

	
	



}