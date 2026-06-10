#include <SFML/Graphics.hpp>
#include <algorithm>
#include <cmath>
#include <iostream>

int main(){
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 4;
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML", sf::State::Windowed, settings);
    window.setKeyRepeatEnabled(false);

    while(window.isOpen()){

        while(auto event = window.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                window.close();
            }
            
            else if(event->is<sf::Event::Resized>()){
                sf::View view(sf::FloatRect({0.f, 0.f}, sf::Vector2f(window.getSize())));
                window.setView(view);
            }
            
            else if(auto* key = event->getIf<sf::Event::KeyPressed>()){
                if(key->scancode >= sf::Keyboard::Scancode::A && key->scancode <= sf::Keyboard::Scancode::Z){
                    if(key->shift)std::cout << "shift + ";
                    std::cout << sf::Keyboard::getDescription(key->scancode).toAnsiString();
                    std::cout << " key is pressed" << '\n';
                }
            }

            else if(auto* key = event->getIf<sf::Event::KeyReleased>()){
                if(key->scancode >= sf::Keyboard::Scancode::A && key->scancode <= sf::Keyboard::Scancode::Z){
                    if(key->shift)std::cout << "Shift + ";
                    std::cout << sf::Keyboard::getDescription(key->scancode).toAnsiString();
                    std::cout << " key is released" << '\n';
                }
            }
        }
    }
    return 0;
}