#ifndef ANIMAL4_H
#define ANIMAL4_H

#include "Animal.h"
#include "AnimationAnimal4.h"

class Animal4 : public Animal {
private:
	AnimationAnimal4 animationAnimal4;

public:
	Animal4();
	Animal4(float xPos, float yPos);

	void clearAnimation();

	void updatePosition(float speed) override;
	void draw(RenderWindow& window) override;
};

#endif // !1
