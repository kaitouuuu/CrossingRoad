#include "MainMenu.h"

MainMenu::MainMenu(vector<TextBox> mainMenuText, vector<Button> mainMenuButton)
{
    for (int i = 0; i < mainMenuText.size(); ++i) {
        this->mainMenuText.push_back(mainMenuText[i]);
    }

    for (int i = 0; i < mainMenuButton.size(); ++i) {
        this->mainMenuButton.push_back(mainMenuButton[i]);
    }
}

void MainMenu::draw(RenderWindow& window, Vector2f& mouse)
{
    int n = mainMenuText.size();
    for (int i = 0; i < n; ++i) {
        mainMenuText[i].draw(window);
    }

    int m = mainMenuButton.size();
    for (int i = 0; i < m; ++i) {
        mainMenuButton[i].draw(window, mouse);
    }
}