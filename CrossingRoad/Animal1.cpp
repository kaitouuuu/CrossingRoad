#include "Animal1.h"

Animal1::Animal1()
{

}

Animal1::Animal1(float xPos, float yPos) : Animal(xPos, yPos, "Cat")
{
	AnimationAnimal1 tmp("Content/Image/CatAnimated.png", xPos, yPos, 48.f, 48.f, true, false);
	animationAnimal1 = tmp;
}

void Animal1::clearAnimation()
{
	animationAnimal1.gameOver();
}

void Animal1::updatePosition(float speed)
{
	Animal::updatePosition(speed);
	animationAnimal1.update(speed);
}

void Animal1::draw(RenderWindow& window)
{
	Animal::draw(window);
	animationAnimal1.draw(window);
}
