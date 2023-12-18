#include "TrafficLight.h"

void TrafficLight::changeLightState()
{
	color = (color + 1) % 3;
}

const float TrafficLight::getCurrentDuration(int &color)
{
	switch (color)
	{
	case 0:
		return greenDuration;
		break;
	case 1:
		return yellowDuration;
		break;
	case 2:
		return redDuration;
		break;
	default:
		return 0.0f;
		break;
	}
}

void TrafficLight::operation()
{
	    sf::Time deltaTime = clock.restart();
		remainTime -= deltaTime.asSeconds();
		//std::cout << color << " " << remainTime << std::endl;
		if (remainTime < 0)
		{
			changeLightState();
			remainTime = getCurrentDuration(color);
		}
}

float TrafficLight::getX() const
{
	return x;
}

float TrafficLight::getY() const
{
	return y;
}

int TrafficLight::getColor() const
{
	return color;
}

void TrafficLight::draw(sf::RenderWindow& window) {
	if (color == 0) {
		if (!texture.loadFromFile("Content/Image/TrafficLightGreen.png")) {
			std::cout << "Can not load image\n";

			exit(0);
		}
	}
	else if (color == 1) {
		if (!texture.loadFromFile("Content/Image/TrafficLightYellow.png")) {
			std::cout << "Can not load image\n";

			exit(0);
		}
	}
	else {
		if (!texture.loadFromFile("Content/Image/TrafficLightRed.png")) {
			std::cout << "Can not load image\n";

			exit(0);
		}
	}

	sprite.setTexture(texture);
	sprite.setPosition(x, y);

	window.draw(sprite);
}