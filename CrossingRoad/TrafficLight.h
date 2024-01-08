#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include <chrono>
#include <windows.h>
#include <cstdlib>

class TrafficLight
{
private:
	float x;
	float y;

	int color;

	sf::Texture texture;
	sf::Sprite sprite;

	sf::Clock clock;
	float remainTime;
	float redDuration;
	float greenDuration;
	float yellowDuration;
	// Green:0, Yellow: 1, Red: 2

public:
	TrafficLight();

	TrafficLight(float xRoad, float yRoad);

	float getX() const;

	float getY() const;

	int getColor() const;

	void changeLightState();

	const float getCurrentDuration(int &color);

	void operation();

	void draw(sf::RenderWindow& window);
};
