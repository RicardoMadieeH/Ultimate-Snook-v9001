#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <deque>
#include "Vector2i.h"

enum Dir {UP, LEFT, DOWN, RIGHT};
enum StateOfGame {RUNNING, FINISHED_WIN, FINISHED_LOSS};

class Snake {
	std::deque<Vector2i*> body;
	Vector2i fruit;
	StateOfGame StateOfGame;
	Dir direction;
	bool isGrowing = false;

	sf::Clock clk;
	sf::Time time;

public:
	Snake();

	void startSnake();
	void updateSnake();
	void turnUp();
	void turnLeft();
	void turnDown();
	void turnRight();
	void moveSnake();
	void eatFruit();

	bool collision() const;
	bool isBody(int x, int y) const;
	
	int getLength() const;


	void generateFruit();

};


#endif SNAKE_H