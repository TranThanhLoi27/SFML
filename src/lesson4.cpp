#include <SFML/Graphics.hpp>

int main(){
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 4;
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML", sf::State::Windowed, settings);
    sf::CircleShape circle(200.f, 60);
    circle.setOrigin({200.f, 200.f});
    circle.setFillColor({100, 50, 30});
    circle.setOutlineThickness(-1.f);
    circle.setOutlineColor({0, 0, 0});
    circle.setPosition({400.f, 300.f});
    while(window.isOpen()){

        while(auto event = window.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                window.close();
            }
            
            if(event->is<sf::Event::Resized>()){
                sf::View view(sf::FloatRect({0.f, 0.f}, sf::Vector2f(window.getSize())));
                window.setView(view);
            }

            window.clear({72, 50, 200});
            window.draw(circle);
            window.display();
        }
    }
    return 0;
}