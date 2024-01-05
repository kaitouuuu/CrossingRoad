#ifndef ANIMAL1_H
#define ANIMAL1_H

#include "Animal.h"
#include "AnimationAnimal1.h"

class Animal1 : public Animal {
private:
	AnimationAnimal1 animationAnimal1;

public:
	Animal1();
	Animal1(float xPos, float yPos);

	void updatePosition(float speed) override;
	void draw(RenderWindow& window) override;
};
#endif // !1
