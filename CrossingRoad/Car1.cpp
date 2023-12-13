#include "Car1.h"

void Car1::draw(RenderWindow& window)
{
	Sprite tmp = getSprite();
	tmp.setColor(Color(255, 165, 79));
	setSprite(tmp);

	Vehicle::draw(window);
}