#include <SFML/Graphics.hpp>
#include <algorithm>
#include <cmath>
#include <iostream>

int main(){
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 4;
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML", sf::State::Windowed, settings);
    //window.setKeyRepeatEnabled(false);
    sf::RectangleShape button({200, 100});
    button.setOrigin(button.getGeometricCenter());
    while(window.isOpen()){
        auto position = sf::Vector2f(sf::Mouse::getPosition(window));
        while(auto event = window.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                window.close();
            }
            
            else if(event->is<sf::Event::Resized>()){
                sf::View view(sf::FloatRect({0.f, 0.f}, sf::Vector2f(window.getSize())));
                window.setView(view);
            }
        }

        button.setPosition({(float)(window.getSize().x) / 2, (float)(window.getSize().y) / 2});
        
        button.setFillColor(sf::Color::White);
        if(button.getGlobalBounds().contains(position)){
            button.setFillColor(sf::Color::Blue);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
                button.setFillColor(sf::Color::Green);
            }
        }
        window.clear({64, 64, 64});
        window.draw(button);
        window.display();
    }
    return 0;
}