#ifndef VECTOR2I_H
#define VECTOR2I_H

class Vector2i 
{
	
	int x;
	int y;
public:
	Vector2i() {};
	Vector2i(int x, int y);
	int getX() const;
	int getY() const;
	void setX(int x);
	void setY(int y);
	
};

#endif