#include <SFML/Graphics.hpp>
#include <algorithm>
#include <cmath>
#include <iostream>
int main(){
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 4;
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML", sf::State::Windowed, settings);
    int data[] = {1, 3, 2, 4, 8};
    int data_n = sizeof(data) / sizeof(data[0]);
    int data_max = *std::max_element(data, data + data_n);
    //dot
    sf::CircleShape dot;
    dot.setFillColor({0, 170, 255});
    dot.setOutlineColor({0, 0, 0});

    //line
    sf::RectangleShape line;
    line.setFillColor(dot.getFillColor());
    line.setOutlineColor(dot.getOutlineColor());

    while(window.isOpen()){

        while(auto event = window.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                window.close();
            }
            
            if(event->is<sf::Event::Resized>()){
                sf::View view(sf::FloatRect({0.f, 0.f}, sf::Vector2f(window.getSize())));
                window.setView(view);
            }

           
        }
        window.clear({64, 64, 64});

        float window_w = window.getSize().x;
        float window_h = window.getSize().y;

        float scale = 0.8f * window_h / data_max;
        float size = 0.02f * std::min(window_w, window_h);
        float space = 0.6f * window_w / data_n;
        
        float odd_x;
        float odd_y;

        for(int i = 0; i < data_n; i++){
            dot.setRadius(size);
            dot.setOrigin({size, size});
            dot.setOutlineThickness(0.1 * size);
            dot.setPosition({space * (i + 1), window_h - scale * data[i]});
            window.draw(dot);
            float x = dot.getPosition().x;
            float y = dot.getPosition().y;

            //line
            if(i > 0){
                float dx = odd_x - x;
                float dy = odd_y - y;
                float angle = std::atan2(dy, dx);
                line.setRotation(sf::radians(angle));
                float length = std::sqrt(dx * dx + dy * dy);
                line.setSize({length, dot.getRadius()});
                line.setOrigin({0.f, dot.getRadius() / 2});
                //line.setOutlineThickness(dot.getOutlineThickness());
                line.setPosition(dot.getPosition());
                window.draw(line);
            }
            odd_x = x;
            odd_y = y;
        }
       
        window.display();
    }
    return 0;
}