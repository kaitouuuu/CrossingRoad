
#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class TextBox
{
private:
    Text content;
    Font font;

public:
    TextBox(const string& fontPath, const Color& color, const string& text, unsigned int size, float x, float y);
    void draw(RenderWindow& window);
};