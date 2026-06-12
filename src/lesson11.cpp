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
    sf::Font font("C:/Windows/Fonts/arial.ttf");
    sf::Text text(font, "Hello, My name's Loi", 50);
    sf::FloatRect bound = text.getGlobalBounds();
    text.setOrigin(bound.getCenter());
    while(window.isOpen()){
        while(auto event = window.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                window.close();
            }
            
            else if(event->is<sf::Event::Resized>()){
                sf::View view(sf::FloatRect({0.f, 0.f}, sf::Vector2f(window.getSize())));
                window.setView(view);
            }
        }
        float w = window.getSize().x;
        float h = window.getSize().y;
        // right align
        // text.setPosition({w - (bound.size.x) / 2, h / 2});
        // left align
        text.setPosition({bound.size.x / 2, h / 2});
        // right align
        // text.setFillColor(sf::Color::Blue);
        
        window.clear({64, 64, 64});
        window.draw(text);
        window.display();
    }
    return 0;
}