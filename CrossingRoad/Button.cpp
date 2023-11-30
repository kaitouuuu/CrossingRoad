#include "Button.h"

Button::Button(string fileName, float x, float y)
{
    state = 0;
    texture.loadFromFile(fileName);
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
    this->fileName = fileName;
}

Button::~Button()
{

}

bool Button::isMoved(Vector2f& mouse)
{
    return sprite.getGlobalBounds().contains(mouse);
}

bool Button::isClicked(Vector2f& mouse)
{
    return (Mouse::isButtonPressed(Mouse::Left) && sprite.getGlobalBounds().contains(mouse));
}

//void Button::changeState(Vector2f& mouse)
//{
//    if (isClicked(mouse)) {
//        state = 2;
//    }
//    else if (isMoved(mouse)) {
//        state = 1;
//    }
//    else {
//        state = 0;
//    }
//}

void Button::draw(RenderWindow& app, Vector2f& mouse)
{
    //changeState(mouse);

    string newFileName = fileName;
    for (int i = 0; i < 5; ++i) {
        newFileName.pop_back();
    }

    if (state == 0) {
        newFileName += "0.png";
    }
    //else if (state == 1) {
    //    newFileName += "1.png";
    //}
    //else {
    //    newFileName += "2.png";
    //}

    //texture.loadFromFile(newFileName);
    sprite.setTexture(texture);
    app.draw(sprite);
}

FloatRect Button::getGlobalBound() {
    return sprite.getGlobalBounds();

}
