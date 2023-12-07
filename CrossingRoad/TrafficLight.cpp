#include "TrafficLight.h"

void TrafficLight::changeLightState(int &curState)
{
	if (curState == 0)
		state = 1;
	else if (curState == 1)
		state = 2;
	else if (curState == 2)
		state = 0;
}

const float TrafficLight::getCurrentDuration(int &state)
{
	switch (state)
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

void TrafficLight::operation(sf::RenderWindow &window)
{
	float currentTime = 0.f;
	std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed)
				window.close();
		std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();
		std::chrono::duration<float> elapsedTime = currentTime - startTime;
		timer = elapsedTime.count();
		if (timer >= getCurrentDuration(state))
		{
			timer -= getCurrentDuration(state);
			changeLightState(state);
			// std::cout << state << 111 << std::endl;
			startTime = currentTime;
		}
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
