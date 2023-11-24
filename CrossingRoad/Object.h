#ifndef OBJECT_H
#define OBJECT_H

#include <string>

class Object {
private:
	float xPos;
	float yPos;
	int width;
	int height;
	std::string type;

public:
	Object();
	Object(float xPos, float yPos, int width, int height, std::string type);

	float getX() const;
	float getY() const;
	int getWidth() const;
	int getHeight() const;
	std::string getType() const;
};

#endif // OBJECT_H
