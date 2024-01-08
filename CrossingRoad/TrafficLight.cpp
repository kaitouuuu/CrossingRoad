#include "TrafficLight.h"

TrafficLight::TrafficLight(float xRoad, float yRoad): color(rand() % 2), x(xRoad), y(yRoad), remainTime(6),
                                                      redDuration(1 + rand() % 5), greenDuration(5 + rand() % 11), yellowDuration(5) {}

TrafficLight::TrafficLight()
	: x(0), y(0), color(0), redDuration(0), greenDuration(0), yellowDuration(0), remainTime(0)
{}
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