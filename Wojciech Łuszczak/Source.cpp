//#include "SFML/Graphics.hpp"
//#include <iostream>
//
//sf::Sprite sprite;
//
//
//void attack(sf::RenderWindow* m_window) {
//    sf::Texture texture;
//    texture.loadFromFile("images/attackAnimation/swordAttack.png");
//    sf::Clock clock;
//    sf::IntRect rectSourceSprite(0, 0, 64, 64);
//    sf::Sprite sprite(texture, rectSourceSprite);
//    rectSourceSprite.left = 0;
//
//    for (int i = 0; i <= 7; i++) {
//    if (clock.getElapsedTime().asSeconds() > 0.05f) {
//        rectSourceSprite.left += 64;
//        sprite.setTextureRect(rectSourceSprite);
//        clock.restart();
//    }
//    m_window->clear();
//    m_window->draw(sprite);
//    m_window->display();
//    }
//}
//
//
//int main(int argc, char** argv) {
//    sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "Demo Game");
//    renderWindow.setFramerateLimit(15);
//    sf::Event event;
//
//    while (renderWindow.isOpen()) {
//        while (renderWindow.pollEvent(event)) {
//            if (event.type == sf::Event::EventType::Closed)
//                renderWindow.close();
//        }
//        attack(&renderWindow);        
//    }
//}