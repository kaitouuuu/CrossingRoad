//#pragma once
//#include "MainMenu.h"
//class KeyboardSettingsApp {
//public:
//    KeyboardSettingsApp() : window(sf::VideoMode(400, 300), "Keyboard Settings") {
//        // Set default key mappings
//        keyMap = {
//            {"Move Left", sf::Keyboard::A},
//            {"Move Right", sf::Keyboard::D},
//            {"Move Up", sf::Keyboard::W},
//            {"Move Down", sf::Keyboard::S},
//            {"Change Skin", sf::Keyboard::Tab}
//            // Add more actions and default keys as needed
//        };
//
//        createButtons();
//    }
//
//    void run() {
//        while (window.isOpen()) {
//            sf::Event event;
//            while (window.pollEvent(event)) {
//                if (event.type == sf::Event::Closed) {
//                    window.close();
//                }
//                else if (event.type == sf::Event::MouseButtonReleased) {
//                    handleMouseClick(event.mouseButton.x, event.mouseButton.y);
//                }
//                else if (event.type == sf::Event::TextEntered) {
//                    handleTextInput(event.text.unicode);
//                }
//            }
//
//            window.clear();
//            drawButtons();
//            window.display();
//        }
//    }
//
//private:
//    sf::RenderWindow window;
//    std::map<std::string, sf::Keyboard::Key> keyMap;
//    std::string selectedAction; // The action currently being customized
//
//    std::map<std::string, sf::RectangleShape> buttons;
//
//    void createButtons() {
//        
//
//        float offsetY = 20.0f;
//        for (const auto& pair : keyMap) {
//            const std::string& action = pair.first;
//
//            sf::RectangleShape button(sf::Vector2f(200.0f, 30.0f));
//            button.setFillColor(sf::Color::Black);
//            button.setPosition(10.0f, offsetY);
//
//            sf::Text buttonText(action, font, 16);
//            buttonText.setPosition(20.0f, offsetY + 5.0f);
//
//            buttons[action] = button;
//
//            offsetY += 40.0f;
//        }
//    }
//
//    void drawButtons() {
//        for (const auto& pair : buttons) {
//            window.draw(pair.second);
//        }
//    }
//
//    void handleMouseClick(float x, float y) {
//        for (const auto& pair : buttons) {
//            const std::string& action = pair.first;
//            const sf::RectangleShape& button = pair.second;
//
//            if (button.getGlobalBounds().contains(x, y)) {
//                selectedAction = action;
//                std::cout << "Click on button: " << action << ". Now, type a key to customize." << std::endl;
//                return;
//            }
//        }
//    }
//
//    void handleTextInput(sf::Uint32 unicode) {
//        if (!selectedAction.empty() && isprint(unicode)) {
//            // Update the key mapping for the selected action
//            keyMappings[selectedAction] = static_cast<sf::Keyboard::Key>(unicode);
//            std::cout << "Key for " << selectedAction << " has been set to " << static_cast<char>(unicode) << std::endl;
//            selectedAction.clear();
//        }
//    }
//};