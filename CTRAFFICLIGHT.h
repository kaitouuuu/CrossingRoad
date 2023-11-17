
#include<iostream>
#include "SFML/Graphics.hpp"
#include <chrono>
#include <windows.h>
class CTRAFFICLIGHT
{
private:
	sf::Vector2f lightPos;

	char state;

	float timer;
	const float redDuration = 3.f;
	const float greenDuration = 5.f;
	const float yellowDuration = 0.8f;
public:
	CTRAFFICLIGHT() : state('G'), timer(0.0f) {};

	void setLightPos(float lightX, float lightY);

	void changeLightState(char state);

	const float getCurrentDuration(char state);

	void operation(sf::RenderWindow& window);

};
