#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class TextBox
{
private:
    Text content;
    Font font;
    std::string fontPath;
    Color color;
    std::string text;
    int size;
    float x;
    float y;

public:
    TextBox(const std::string& fontPath, const Color& color, const std::string& text, unsigned int size, float x, float y);
    void setText(const std::string& text);
    std::string getText();
    void draw(RenderWindow& window);
};

#endif // TEXTBOX_H
