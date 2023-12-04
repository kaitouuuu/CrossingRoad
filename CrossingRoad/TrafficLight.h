#include "SFML/Graphics.hpp"
#include <iostream>
#include <chrono>
#include <windows.h>
class CTRAFFICLIGHT
{
private:
	float x;
	float y;

	int state;

	float timer;
	const float redDuration = 3.f;
	const float greenDuration = 5.f;
	const float yellowDuration = 0.8f;

public:
	CTRAFFICLIGHT(float xRoad, float yRoad) : state(0), timer(0.0f), x(xRoad), y(yRoad) {}

	void changeLightState(int &state);

	const float getCurrentDuration(int &state);

	void operation(sf::RenderWindow &window);
};
