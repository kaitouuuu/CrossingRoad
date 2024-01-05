#include "Animal3.h"

Animal3::Animal3()
{

}

Animal3::Animal3(float xPos, float yPos) : Animal(xPos, yPos, "Fox")
{
	AnimationAnimal3 tmp("Content/Image/FoxAnimated.png", xPos, yPos, 48.f, 48.f, true, false);
	animationAnimal3 = tmp;
}

void Animal3::updatePosition(float speed)
{
	Animal::updatePosition(speed);
	animationAnimal3.update(speed);
}

void Animal3::draw(RenderWindow& window)
{
	Animal::draw(window);
	animationAnimal3.draw(window);
}
