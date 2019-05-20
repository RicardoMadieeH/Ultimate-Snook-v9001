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
	
	Vector2i fruit;
	StateOfGame stateOfGame;
	Dir direction;
	bool isGrowing = false;

	sf::Clock clk;
	sf::Time time;

public:
	std::deque<Vector2i*> body;
	
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

	int getFruitX();
	int getFruitY();

	StateOfGame getStateOfGame();

};


#endif SNAKE_H