
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
    string fontPath;
    Color color;
    string text;
    int size;
    float x;
    float y;

public:
    TextBox(const string& fontPath, const Color& color, const string& text, unsigned int size, float x, float y);
    void setText(const string& text);
    std::string getText();
    void draw(RenderWindow& window);
};