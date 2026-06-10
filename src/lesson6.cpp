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

    sf::CircleShape dot;
    dot.setFillColor({0, 100, 150});
    sf::RectangleShape line;
    line.setFillColor(dot.getFillColor());

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
        
        float window_w = window.getSize().x;
        float window_h = window.getSize().y;
        float scale = 0.7f * window_h / data_max;
        float r = 0.02f * std::min(window_w, window_h);
        float space = window_w / (data_n - 1);
        window.clear({64, 64, 64});
        
        float odd_x;
        float odd_y;

        sf::ConvexShape area;
        area.setPointCount(4);
        area.setFillColor({0, 127, 191});

        for(int i = 0; i < data_n; i++){
            float x = space * i;
            float y = window_h - scale * data[i];

            if(i > 0){
                area.setPoint(0, {odd_x, window_h});
                area.setPoint(1, {odd_x, odd_y});
                area.setPoint(2, {x, y});
                area.setPoint(3, {x, window_h});
                window.draw(area);
            }
            odd_x = x;
            odd_y = y;
        }
       
        
        for(int i = 0; i < data_n; i++){
            float x = space * i;
            float y = window_h - scale * data[i];
            dot.setRadius(r);
            dot.setOrigin({r, r});
            dot.setPosition({x, y});
            window.draw(dot);
            if(i > 0){
                float dx = odd_x - x;
                float dy = odd_y - y;
                float angle = std::atan2(dy, dx);
                float length = std::sqrt(dx * dx + dy * dy);
                line.setSize({length, 2 * r});
                line.setOrigin({0.f, r});
                line.setPosition({x, y});
                line.setRotation(sf::radians(angle));
                window.draw(line);
            }
            odd_x = x;
            odd_y = y;
        }
        window.display();
    }
    return 0;
}