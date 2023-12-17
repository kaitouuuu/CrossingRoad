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
	TrafficLight() : color(0), x(0), y(0) {}

	TrafficLight(float xRoad, float yRoad) : color(rand() % 3), x(xRoad), y(yRoad), remainTime(6),
											 redDuration(1 + rand() % 5), greenDuration(5 + rand() % 11), yellowDuration(5) {}

	float getX() const;

	float getY() const;

	int getColor() const;

	void changeLightState();

	const float getCurrentDuration(int &color);

	void operation();

	void draw(sf::RenderWindow& window);
};
