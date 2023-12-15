#ifndef ANIMAL1_H
#define ANIMAL1_H
#include "Animal.h"

class Animal1 : public Animal {
public:
	Animal1(float xPos, float yPos, std::string type) : Animal(xPos, yPos, type) {}

	void draw(RenderWindow& window) override;
};
#endif // !1
