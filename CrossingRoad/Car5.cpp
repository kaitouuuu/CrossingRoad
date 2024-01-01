#include "Car5.h"

Car5::Car5()
{

}

Car5::Car5(float xPos, float yPos) : Vehicle(xPos, yPos, "Yellow")
{
	AnimationCar5 tmp("Content/Image/YellowCarSprite.png", xPos, yPos, 72.f, 52.f, true, false);
	animationCar5 = tmp;
}

void Car5::updatePosition(float speed, bool isappearEsc)
{
	Vehicle::updatePosition(speed,isappearEsc);
	
	animationCar5.update(speed,isappearEsc);
}

void Car5::draw(RenderWindow& window)
{
	Vehicle::draw(window);
	animationCar5.draw(window);
}