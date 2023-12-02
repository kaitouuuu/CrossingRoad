#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;
enum class buttonState {
    unclick,click,touch
};
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
    string Stype;

public:
    Button(string fileName, float x, float y,string typee   );
    ~Button();

    bool isMoved(Vector2f& mouse);
    bool isClicked(Vector2f& mouse);
    const string type();
    //void changeState(Vector2f& mouse);
    void draw(RenderWindow& app, Vector2f& mouse);
    FloatRect getGlobalBound();
};