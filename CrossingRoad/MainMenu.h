#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "TextBox.h"
#include "Button.h"

using namespace sf;
using namespace std;

class MainMenu
{
private:
    vector<TextBox> mainMenuText;
    vector<Button> mainMenuButton;

public:
    MainMenu(vector<TextBox> mainMenuText, vector<Button> mainMenuButton);
    void draw(RenderWindow& window, Vector2f& mouse);
};