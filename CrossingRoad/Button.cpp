#include "Button.h"

Button::Button(std::string fileName, float x, float y, std::string type = "default")
{
	state = 0;
	texture.loadFromFile(fileName);
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
	this->fileName = fileName;
	Stype = type;
}

const std::string Button::type()
{
	return Stype;
}

Button::~Button()
{
}

bool Button::isMoved(Vector2f& mouse)
{
	return sprite.getGlobalBounds().contains(mouse);
}

bool Button::isClicked(Vector2f& mouse)
{
	return (Mouse::isButtonPressed(Mouse::Left) && sprite.getGlobalBounds().contains(mouse));
}

void Button::draw(RenderWindow& app, Vector2f& mouse)
{
	std::string newFileName = fileName;
	for (int i = 0; i < 5; ++i)
	{
		newFileName.pop_back();
	}

	if (state == 0)
	{
		newFileName += "0.png";
	}

	sprite.setTexture(texture);
	app.draw(sprite);
}

FloatRect Button::getGlobalBound()
{
	return sprite.getGlobalBounds();
}
