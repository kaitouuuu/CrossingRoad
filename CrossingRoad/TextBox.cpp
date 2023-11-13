#include "TextBox.h"

TextBox::TextBox(const string& fontPath, const Color& color, const string& text, unsigned int size, float x, float y)
{
    if (!font.loadFromFile(fontPath))
    {
        cout << "Error loading font from file: " << fontPath << endl;
    }

    content.setFont(font);
    content.setFillColor(color);
    content.setString(text);
    content.setCharacterSize(size);
    content.setPosition(x, y);
}

void TextBox::draw(RenderWindow& window)
{
    window.draw(content);
}