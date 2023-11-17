#include"SFML/Graphics.hpp"
#include "CTRAFFICLIGHT.h"


void CTRAFFICLIGHT::setLightPos(float setX, float setY)
{
	lightPos.x = setX;
	lightPos.y = setY;
}

void CTRAFFICLIGHT::changeLightState(char curState) 
{
	if (curState == 'G')
		state = 'Y';
	else if (curState == 'Y')
		state = 'R';
	else if (curState == 'R')
		state = 'G';
}

const float CTRAFFICLIGHT::getCurrentDuration(char state)
{
	switch (state)
	{
	case 'G':
		return greenDuration;
		break;
	case 'Y':
		return yellowDuration;
		break;
	case 'R':
		return redDuration;
		break;
	default:
		return 0.0f;
		break;
	}
}

void CTRAFFICLIGHT::operation(sf::RenderWindow &window)
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
		if ( timer >= getCurrentDuration(state))
		{
			timer -= getCurrentDuration(state);
			changeLightState(state);
			std::cout << state << 111 << std::endl;
			startTime = currentTime;
		}
	}
}

