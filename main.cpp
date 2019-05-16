#include <SFML/Graphics.hpp>
#include <iostream>

#include "Snake.h"
#include "IntroView.h"
#include "IntroController.h"
#include "SnakeView.h"
#include "SnakeController.h"
#include "ScoreView.h"
#include "ScoreController.h"
#include "GameManager.h"


int main() {

	sf::RenderWindow win(sf::VideoMode(1280, 720), "Ultimate Snook v9001", sf::Style::Titlebar | sf::Style::Close);

	Snake snake;

	IntroView iv;
	IntroController intro(iv, win);
	
	SnakeView sv(snake);
	SnakeController game(sv, win);

	ScoreView scv;
	ScoreController score(scv, win);





	GameManager gm(intro, game, score);

	// Start the game loop
	while (win.isOpen()) {
		// Process events
		sf::Event event;
		while (win.pollEvent(event)) {
			// Close window : exit
			if (event.type == sf::Event::Closed) {
				win.close();
			}

			gm.handleEvent(event);

		}

		// Clear screen
		win.clear();

		// Draw current state
		gm.draw(win);

		// Update the window
		win.display();
	}




	return 0;
}