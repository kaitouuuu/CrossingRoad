#ifndef ANIMAL3_H
#define ANIMAL3_H

#include "Animal.h"
#include "AnimationAnimal3.h"

class Animal3 : public Animal {
private:
	AnimationAnimal3 animationAnimal3;

public:
	Animal3();
	Animal3(float xPos, float yPos);

	void updatePosition(float speed) override;
	void draw(RenderWindow& window) override;
};
#endif // !1
