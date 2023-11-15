#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Button
{
private:
    Sprite sprite;
    Texture texture;
    string fileName;

    int state = 0;

    float x;
    float y;
    float speed;

public:
    Button(string fileName, float x, float y);
    ~Button();

    bool isMoved(Vector2f& mouse);
    bool isClicked(Vector2f& mouse);

    void changeState(Vector2f& mouse);
    void draw(RenderWindow& app, Vector2f& mouse);
};