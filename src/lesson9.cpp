#include <SFML/Graphics.hpp>
#include <algorithm>
#include <cmath>
#include <iostream>

int main(){
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 4;
    sf::RenderWindow window(sf::VideoMode({200, 200}), "SFML", sf::State::Windowed, settings);
    //window.setKeyRepeatEnabled(false);
    bool isPressed = 0;
    while(window.isOpen()){

        while(auto event = window.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                window.close();
            }
            
            else if(event->is<sf::Event::Resized>()){
                sf::View view(sf::FloatRect({0.f, 0.f}, sf::Vector2f(window.getSize())));
                window.setView(view);
            }

            else if(auto* mouse = event->getIf<sf::Event::MouseButtonPressed>()){
                if(mouse->button == sf::Mouse::Button::Left){
                    std::cout << "Attack" << '\n';
                }
            }

            else if(auto* wheel = event->getIf<sf::Event::MouseWheelScrolled>()){
                std::cout << wheel->delta << '\n';
            }
        }
        window.clear({64, 64, 64});
        //mouse position
        // sf::Vector2i position = sf::Mouse::getPosition(window);
        // std::cout << position.x << " " << position.y << '\n';
        // sf::RectangleShape cursor({100.f, 100.f});
        // cursor.setOrigin({0.f, 0.f});
        // cursor.setPosition(sf::Vector2f(position));
        // window.draw(cursor);

        // if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
        //     if(!isPressed){
        //         std::cout << "Attack" << '\n';
        //         isPressed = 1;
        //     }
        // }
        // else isPressed = 0;

        // if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)){
        //     if(!isPressed){
        //         std::cout << "Place Block" << '\n';
        //     }
        // }

        // if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Middle)){
        //     std::cout << "magic" <<'\n';
        // }
        // if(auto* wheel = sf::Mouse::isButtonPressed(sf::Mouse::Wheel::Vertical)){

        // }
        window.display();
    }
    return 0;
}