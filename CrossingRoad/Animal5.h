#ifndef ANIMAL5_H
#define ANIMAL5_H

#include "Animal.h"
#include "AnimationAnimal5.h"

class Animal5 : public Animal {
private:
	AnimationAnimal5 animationAnimal5;

public:
	Animal5();
	Animal5(float xPos, float yPos);

	void updatePosition(float speed) override;
	void draw(RenderWindow& window) override;
};

#endif // !1
