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

    vector<Button> mainMenuButton;
    string type;
public:
    MainMenu(vector<Button> mainMenuButton);
    void draw(RenderWindow& window, Vector2f& mouse);
    void updateState(string type);
    void game();
    void highscore();
    void exit();
    void rule();
    void setting();

};
