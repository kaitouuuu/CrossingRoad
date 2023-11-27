#pragma once
#include <vector>
class Object {
private:
	float x;
	float y;
	float width;
	float height;

public:
	Object(float x, float y, float width, float height);
	float getX();
	float getY();
	float getWidth();
	float getHeight();
};

class Car : public Object {
private:
	float speed;
public:
	void display();
};

class Obstacle : public Object {

public:
	void display();
};

class Superlane {
private:
	float y;
	float x;
public:

};
class lane : public Superlane {
private:
	std::vector<Obstacle*> smallobstacle;
};
class road : public Superlane {
private:
	std::vector<Car*> vehicle;
};
