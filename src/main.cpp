#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Mario");
    
    //create rectangegle
    sf::RectangleShape rectangle({400.f, 200.f});

    //set origin
    rectangle.setOrigin({200.f, 100.f});

    //color and outline
    rectangle.setFillColor({120, 50, 79});
    rectangle.setOutlineThickness(10.f);
    rectangle.setOutlineColor({10, 20, 30});

    //transformation
    //rectangle.setScale({1.5f, 1.f});
    rectangle.setRotation(sf::degrees(30.f));
    rectangle.setPosition({400.f, 300.f});
    
    
    while(window.isOpen()){
        while(auto event = window.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                window.close();
            }
            if(event->is<sf::Event::Resized>()){
                //change view
                sf::View view({400.f, 300.f}, sf::Vector2f(window.getSize()));
                window.setView(view);
            }
        }   
        window.clear(sf::Color(100, 200, 200));
        window.draw(rectangle);
        window.display();
    }
    return 0;
}