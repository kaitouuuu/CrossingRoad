#include "Animal4.h"

Animal4::Animal4()
{
}

Animal4::Animal4(float xPos, float yPos) : Animal(xPos, yPos, "Hedgehog")
{
	AnimationAnimal4 tmp("Content/Image/HedgehogAnimated.png", xPos, yPos, 48.f, 48.f, true, false);
	animationAnimal4 = tmp;
	setWidthHeight(51, 30);
}

void Animal4::clearAnimation()
{
	animationAnimal4.gameOver();
}

void Animal4::updatePosition(float speed,bool isappearEsc)
{
	Animal::updatePosition(speed,isappearEsc);
	animationAnimal4.update(speed,isappearEsc);
}

void Animal4::draw(RenderWindow& window)
{
	Animal::draw(window);
	animationAnimal4.draw(window);
}
