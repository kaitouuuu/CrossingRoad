#include "MainMenu.h"


Menu::Menu(vector<Button>& menu) {
    for (auto& button : menu) {
        this->menu.push_back(button);
    }
};

void Menu::draw(RenderWindow& window, Vector2f& mouse) {
    int m = menu.size();
    for (auto& button : menu) {
        button.draw(window, mouse);
    }
}

MainMenu::MainMenu(vector<Button>& mainMenuButton) : Menu(mainMenuButton) {};
