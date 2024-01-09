#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/keyboard.hpp>
#include <iostream>
#include "TextBox.h"
#include "Button.h"

using namespace sf;

class Menu {
private:
    std::vector<Button> menu;
    std::vector<TextBox> text;

public:
    Menu(const std::vector<Button>& menu, const std::vector<TextBox>& text);
    void draw(RenderWindow& window, Vector2f& mouse);
};

#endif // MENU_H
