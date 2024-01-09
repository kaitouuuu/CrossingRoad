#include "Menu.h"

Menu::Menu(const std::vector<Button>& menu, const std::vector<TextBox>& text)
{
	for (auto& button : menu)
	{
		this->menu.push_back(button);
	}

	for (auto& text : text)
	{
		this->text.push_back(text);
	}
};

void Menu::draw(RenderWindow& window, Vector2f& mouse)
{
	int m = menu.size();
	for (auto& button : menu)
	{
		button.draw(window, mouse);
	}
	for (auto& text : text)
	{
		text.draw(window);
	}
}
