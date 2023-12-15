#include "Animal1.h"

void Animal1::draw(RenderWindow& window)
{
	Sprite tmp = getSprite();
	tmp.setColor(Color(255, 165, 79));
	setSprite(tmp);

	Animal::draw(window);
}