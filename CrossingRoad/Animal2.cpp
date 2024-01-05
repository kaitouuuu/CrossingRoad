#include "Animal2.h"

Animal2::Animal2()
{

}

Animal2::Animal2(float xPos, float yPos) : Animal(xPos, yPos, "Dragonfly")
{
	AnimationAnimal2 tmp("Content/Image/DragonflyAnimated.png", xPos, yPos, 48.f, 48.f, true, false);
	animationAnimal2 = tmp;
}

void Animal2::updatePosition(float speed)
{
	Animal::updatePosition(speed);
	animationAnimal2.update(speed);
}

void Animal2::draw(RenderWindow& window)
{
	Animal::draw(window);
	animationAnimal2.draw(window);
}
