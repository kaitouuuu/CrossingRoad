#ifndef ANIMAL2_H
#define ANIMAL2_H

#include "Animal.h"
#include "AnimationAnimal2.h"

class Animal2 : public Animal {
private:
	AnimationAnimal2 animationAnimal2;

public:
	Animal2();
	Animal2(float xPos, float yPos);

	void clearAnimation();

	void updatePosition(float speed,bool isappearEsc) override;
	void draw(RenderWindow& window) override;
};

#endif // ANIMAL2_H
