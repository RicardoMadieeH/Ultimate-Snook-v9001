#include "Vector2i.h"



Vector2i::Vector2i(int x, int y) :x(x), y(y) {

}

int Vector2i::getX() const {
	return this->x;
}

int Vector2i::getY() const {
	return this->y;
}

void Vector2i::setX(int x) {
	this->x = x;
}

void Vector2i::setY(int y) {
	this->y = y;
}