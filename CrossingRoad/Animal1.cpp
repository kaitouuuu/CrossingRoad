#include "Animal1.h"

Animal1::Animal1(float xPos, float yPos, std::string type) : Animal(xPos, yPos, type)
{
	std::string tmp = "Content/Image/" + type + ".png";
	setTexture(tmp);
	setSprite();
}
