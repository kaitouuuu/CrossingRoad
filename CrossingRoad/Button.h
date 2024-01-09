#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

enum class buttonState {
    unclick, click, touch
};

class Button
{
private:
    Sprite sprite;
    Texture texture;
    std::string fileName;

    int state = 0;

    float x;
    float y;
    float speed;
    std::string Stype;

public:
    Button(std::string fileName, float x, float y,std::string typee   );
    ~Button();

    bool isMoved(Vector2f& mouse);
    bool isClicked(Vector2f& mouse);
    const std::string type();
    void draw(RenderWindow& app, Vector2f& mouse);
    FloatRect getGlobalBound();
};

#endif // BUTTON_H
