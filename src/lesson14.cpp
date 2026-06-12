#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <algorithm>
#include <cmath>
#include <iostream>

int main(){
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 4;
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML", sf::State::Windowed, settings);
    //window.setKeyRepeatEnabled(false);
    window.setFramerateLimit(5);
    sf::Clock clock;
    while(window.isOpen()){
        float dt = clock.getElapsedTime().asSeconds();
        //fixed delta time
        if(dt >= 0.2f){
            clock.restart();
            std::cout << dt <<'\n';
            while(auto event = window.pollEvent()){
                if(event->is<sf::Event::Closed>()){
                    window.close();
                }
                
                else if(event->is<sf::Event::Resized>()){
                    sf::View view(sf::FloatRect({0.f, 0.f}, sf::Vector2f(window.getSize())));
                    window.setView(view);
                }
            }
        
            window.clear({64, 64, 64}); 
            window.display();
        }
    }
    return 0;
}