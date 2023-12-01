#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TextBox.h"
#include "Button.h"

using namespace sf;
using namespace std;

enum class GameState {
    mainmenu,game,setting,highscore, loadgame, newgame
};



class Menu {
private:
    vector<Button> menu;
    vector<TextBox> text;
public:
    Menu(const vector<Button>& menu,const vector<TextBox> & text);
    void draw(RenderWindow& window, Vector2f& mouse) ;
};

class MainMenu: public Menu
{

    
public:
    MainMenu(vector<Button>& mainMenuButton);
    void game();
    void highscore();
    void exit();
    void rule();
    void setting();

};

class Game:public Menu {
public:
    void newgame();
    void loadgame();
};
