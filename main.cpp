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
#include <ctime>


int main() {
	srand(time(0));

	sf::RenderWindow win(sf::VideoMode(1280, 720), "Ultimate Snook v9001", sf::Style::Titlebar | sf::Style::Close);

	win.setFramerateLimit(60);

	Snake snake;
	snake.startSnake();

	IntroView iv;
	IntroController intro(iv, win);
	
	SnakeView sv(snake);
	SnakeController game(sv, win, snake);

	ScoreView scv(snake);
	ScoreController score(scv, win);

	sf::Clock clk;
	sf::Time time;



	GameManager gm(intro, game, score, snake);

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
		snake.updateSnake();
		// Moving snake
		/*
		time = clk.getElapsedTime();
		if (time.asMilliseconds() >= 1000 / 15)
		{
			snake.moveSnake();
			snake.collision();
			clk.restart();
		}
		*/

		// Clear screen
		win.clear();

		// Draw current state
		gm.draw(win);

		// Update the window
		win.display();
	}




	return 0;
}