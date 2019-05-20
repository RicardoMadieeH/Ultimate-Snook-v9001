#include "Snake.h"


Snake::Snake() {

}

bool Snake::isBody(int x, int y) const {
	for (int i = 0; i < body.size()-1; i++) {
		if (x == body[i]->getX() && y == body[i]->getY()) {
			return true;
		}
	}
	return false;
}

void Snake::generateFruit() {
	fruit.setX(5+rand() % 54);
	fruit.setY(5+rand() % 26);

	if (isBody(fruit.getX(), fruit.getY()) == true) {
		generateFruit();
	}
}

int Snake::getLength() const {
	return body.size();
}

void Snake::startSnake() {
	stateOfGame = RUNNING;
	body.push_back(new Vector2i(14, 10));
	body.push_back(new Vector2i(15, 10));
	direction = RIGHT;

	generateFruit();
}

void Snake::updateSnake() {
	time = clk.getElapsedTime();
	if (time.asMilliseconds() >= 1000 / 15) {
		moveSnake();
		eatFruit();

		if (collision() == true) {
			stateOfGame = FINISHED_LOSS;
		}
		else if (getLength() == 54 * 26) {
			stateOfGame == FINISHED_WIN;
		}

		clk.restart();
	}
}

void Snake::turnUp() {
	Vector2i temp(*body.back());
	if (direction != DOWN && isBody(temp.getX(), temp.getY() - 1) == false) {
		direction = UP;
	}
}

void Snake::turnLeft() {
	Vector2i temp(*body.back());
	if (direction != RIGHT && isBody(temp.getX() - 1, temp.getY()) == false) {
		direction = LEFT;
	}
}

void Snake::turnDown() {
	Vector2i temp(*body.back());
	if (direction != UP && isBody(temp.getX(), temp.getY() + 1) == false) {
		direction = DOWN;
	}
}

void Snake::turnRight() {
	Vector2i temp(*body.back());
	if (direction != LEFT && isBody(temp.getX() + 1, temp.getY()) == false) {
		direction = RIGHT;
	}
}

void Snake::moveSnake() {
	if (stateOfGame == RUNNING) {
		Vector2i temp(*body.back());

		if (direction == UP) {
			body.push_back(new Vector2i(temp.getX(), temp.getY() - 1));
			if (!isGrowing) {
				delete body.front();
				body.pop_front();
			}
			else {
				isGrowing = false;
			}
		}
		else if (direction == LEFT) {
			body.push_back(new Vector2i(temp.getX() - 1, temp.getY()));
			if (!isGrowing) {
				delete body.front();
				body.pop_front();
			}
			else {
				isGrowing = false;
			}
		}
		else if (direction == DOWN) {
			body.push_back(new Vector2i(temp.getX(), temp.getY() + 1));
			if (!isGrowing) {
				delete body.front();
				body.pop_front();
			}
			else {
				isGrowing = false;
			}
		}
		else if (direction == RIGHT) {
			body.push_back(new Vector2i(temp.getX() + 1, temp.getY()));
			if (!isGrowing) {
				delete body.front();
				body.pop_front();
			}
			else {
				isGrowing = false;
			}
		}
	}
}

void Snake::eatFruit() {
	if (body.back()->getX() == fruit.getX() && body.back()->getY() == fruit.getY()) {
		isGrowing = true;
		generateFruit();
	}
}

bool Snake::collision() const {
	if (isBody(body.back()->getX(), body.back()->getY()) || body.back()->getX()*20 >= 1180 || body.back()->getX()*20 < 100 || body.back()->getY()*20 >= 620 || body.back()->getY()*20 < 100) {
		return true;
	}
	return false;
}

int Snake::getFruitX() {
	return fruit.getX();
}

int Snake::getFruitY() {
	return fruit.getY();
}

StateOfGame Snake::getStateOfGame() {
	return stateOfGame;
}





