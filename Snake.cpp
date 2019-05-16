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
	fruit.setX(rand() % 31);
	fruit.setY(rand() % 21);

	if (isBody(fruit.getX(), fruit.getY()) == true) {
		generateFruit();
	}
}

int Snake::getLength() const {
	return body.size();
}

void Snake::startSnake() {
	StateOfGame = RUNNING;
	body.push_back(new Vector2i(14, 10));
	body.push_back(new Vector2i(15, 10));
	direction = RIGHT;

	generateFruit();
}

void Snake::updateSnake() {
	time = clk.getElapsedTime();
	if (time.asSeconds() == 1) {
		moveSnake();
		eatFruit();

		if (collision() == true) {
			StateOfGame = FINISHED_LOSS;
		}
		clk.restart();
	}
}

void Snake::turnUp() {
	if (direction != DOWN) {
		direction = UP;
	}
}

void Snake::turnLeft() {
	if (direction != RIGHT) {
		direction = LEFT;
	}
}

void Snake::turnDown() {
	if (direction != UP) {
		direction = DOWN;
	}
}

void Snake::turnRight() {
	if (direction != LEFT) {
		direction = RIGHT;
	}
}

void Snake::moveSnake() {
	if (StateOfGame == RUNNING) {
		Vector2i temp(*body.back());

		if (direction == UP) {
			body.push_back(new Vector2i(temp.getX(), temp.getY()-1));
			if (!isGrowing){
				delete body.front();
				body.pop_front();
			}
			else {
				isGrowing = false;
			}
		}
		else if (direction == LEFT) {
			body.push_back(new Vector2i(temp.getX()-1, temp.getY()));
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
			body.push_back(new Vector2i(temp.getX()+1, temp.getY()));
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
	if (isBody(body.back()->getX(), body.back()->getY()) || body.back()->getX() > 30 || body.back()->getX() < 0 || body.back()->getY() > 20 || body.back()->getY() < 0) {
		return true;
	}
	return false;
}







