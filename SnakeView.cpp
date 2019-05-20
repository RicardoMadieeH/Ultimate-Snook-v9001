#include "SnakeView.h"

SnakeView::SnakeView(Snake &b) :body(b) {

	//Loading Font//
	if (!arial.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-B.ttf")) {
		if (!arial.loadFromFile("C:\\Windows\\Fonts\\arial.ttf")) {
			abort();
		}
	}

	//Loading and Setting Cherry texture//
	if (!cherry.loadFromFile("cherries.png")) {
		std::cout << "Failed to load texture of cherry." << std::endl;
		abort();
	}
	snakeCherry.setTexture(cherry);
	snakeCherry.setScale(sf::Vector2f(0.0390625, 0.0390625)); //Weird scale so 512x512 texture fits on 20x20 field//

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
	snuk.setSize(sf::Vector2f(19, 19)); // (1080/20)=54 // (520/20)=26 // Plansza bedzie miala rozmiar 54x26 pol (aby kazde pole moglo byc kwadratem i waz nie wygladal dziwnie poruszajac sie w pionie)//
	snuk.setOutlineThickness(1);
	snuk.setOutlineColor(sf::Color::Black);

	//Victory Text settings//
	victory.setFont(arial);
	victory.setFillColor(sf::Color::Magenta);
	victory.setCharacterSize(100);
	victory.setString("VICTORY\nPress a key");
	victory.setPosition(sf::Vector2f(430, 300));

	//Defeat Text settings//
	defeat.setFont(arial);
	defeat.setFillColor(sf::Color::Magenta);
	defeat.setCharacterSize(100);
	defeat.setString("DEFEAT\nPress a key");
	defeat.setPosition(sf::Vector2f(450, 300));

}

void SnakeView::draw(sf::RenderWindow &win) {

	win.draw(wall);
	win.draw(board);
	win.draw(txt);
	

	for (int i = 0; i <= body.getLength()-1; i++) {
		snuk.setPosition(sf::Vector2f(body.body[i]->getX()*20, body.body[i]->getY()*20));
		win.draw(snuk);
		
	}

	snakeCherry.setPosition(sf::Vector2f(body.getFruitX() * 20, body.getFruitY() * 20));
	win.draw(snakeCherry);
	
	points = body.getLength() - 2;
	scoreValue.setTextString(std::to_string(points), 50);
	scoreValue.drawTo(win);

	if (body.getStateOfGame() == FINISHED_LOSS) {
		win.draw(defeat);
	}
	else if (body.getStateOfGame() == FINISHED_WIN) {
		win.draw(victory);
	}
	
	

	
	



}