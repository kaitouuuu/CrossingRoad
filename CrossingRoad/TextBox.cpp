#include "TextBox.h"

TextBox::TextBox(const string& fontPath, const Color& color, const string& text, unsigned int size, float x, float y):fontPath(fontPath),color(color),
text(text),size(size),x(x),y(y)
{
    /*if (!font.loadFromFile(fontPath))
    {
        cout << "Error loading font from file: " << fontPath << endl;
    }

    content.setFont(font);
    content.setFillColor(color);
    content.setString(text);
    content.setCharacterSize(size);
    content.setPosition(x, y);*/
}
void TextBox::setText(const string& text) {
    this->text = text;
}
std::string TextBox::getText() {
    return this->text;
}
void TextBox::draw(RenderWindow& window)
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
    window.draw(content);
}