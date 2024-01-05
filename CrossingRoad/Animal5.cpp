#include "Animal5.h"

Animal5::Animal5()
{

}

Animal5::Animal5(float xPos, float yPos) : Animal(xPos, yPos, "Porcupine")
{
	AnimationAnimal5 tmp("Content/Image/PorcupineAnimated.png", xPos, yPos, 48.f, 48.f, true, false);
	animationAnimal5 = tmp;
}

void Animal5::clearAnimation()
{
	animationAnimal5.gameOver();
}

void Animal5::updatePosition(float speed)
{
	Animal::updatePosition(speed);
	animationAnimal5.update(speed);
}

void Animal5::draw(RenderWindow& window)
{
	Animal::draw(window);
	animationAnimal5.draw(window);
}
