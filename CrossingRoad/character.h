#pragma once

enum Skin {
	red, blue, green
};
enum Direction {
	front, left, right
};
class Character {
public:
	void move(const Direction& dir);
	bool collision_car();
	bool collision_obj();
	void changeskin();
	void display();
	bool IsLose() { return islose; }
private:
	float x;
	float y;
	Skin skin;
	bool islose;
};