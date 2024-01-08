#include "Animal2.h"

Animal2::Animal2()
{

}

Animal2::Animal2(float xPos, float yPos) : Animal(xPos, yPos, "Dragonfly")
{
	AnimationAnimal2 tmp("Content/Image/DragonflyAnimated.png", xPos, yPos, 48.f, 48.f, true, false);
	animationAnimal2 = tmp;
}

void Animal2::clearAnimation()
{
	animationAnimal2.gameOver();
}
void Animal2::updatePosition(float speed,bool isappearEsc)
{
	Animal::updatePosition(speed,isappearEsc);
	animationAnimal2.update(speed,isappearEsc);
}

void Animal2::draw(RenderWindow& window)
{
	Animal::draw(window);
	animationAnimal2.draw(window);
}
