#include "Animal3.h"

Animal3::Animal3()
{

}

Animal3::Animal3(float xPos, float yPos) : Animal(xPos, yPos, "Fox")
{
	AnimationAnimal3 tmp("Content/Image/FoxAnimated.png", xPos, yPos, 48.f, 48.f, true, false);
	animationAnimal3 = tmp;
	setWidthHeight(40, 30);
}

void Animal3::clearAnimation()
{
	animationAnimal3.gameOver();
}

void Animal3::updatePosition(float speed,bool isappearEsc)
{
	Animal::updatePosition(speed,isappearEsc);
	animationAnimal3.update(speed,isappearEsc);
}

void Animal3::draw(RenderWindow& window)
{
	Animal::draw(window);
	animationAnimal3.draw(window);
}
