#include "TextBox.h"

TextBox::TextBox(const std::string& fontPath, const Color& color, const std::string& text, unsigned int size, float x, float y) : fontPath(fontPath), color(color),
text(text), size(size), x(x), y(y)
{
}

void TextBox::setText(const std::string& text)
{
	this->text = text;
}

std::string TextBox::getText()
{
	return this->text;
}
void TextBox::draw(RenderWindow& window)
{
	if (!font.loadFromFile(fontPath))
	{
		std::cout << "Error loading font from file: " << fontPath << std::endl;
	}

	content.setFont(font);
	content.setFillColor(color);
    content.setString(text);
	content.setCharacterSize(size);
	content.setPosition(x, y);
	window.draw(content);
}
