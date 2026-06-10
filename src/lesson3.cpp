#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
int main(){ 
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML");
    while(window.isOpen()){
        int data[] = {1, 2, 3, 4, 5};
        int data_n = sizeof(data) / sizeof(data[0]);
        int data_max = *std::max_element(data, data + data_n);
        sf::RectangleShape bar({200.f, 100.f});
        bar.setFillColor({0, 170, 200});
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
        float scale = 0.8f * window_h / data_max;
        float size = 0.6f * window_w / data_n;
        float space = window_w / data_n;
        
        window.clear({70, 70, 70});
        for(int i = 0; i < data_n; i++){
            bar.setSize({size, -scale * data[i]});
            bar.setPosition({space * i + 20.f, window_h});
            bar.setOutlineThickness(-2.f);
            bar.setOutlineColor({0, 0, 50});

            window.draw(bar);
        }
        window.draw(bar);
        window.display();

    }

    return 0;
}