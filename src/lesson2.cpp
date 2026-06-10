#include <SFML/Graphics.hpp>
#include <iostream>
int main(){
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Mario");
    
    //top_left
    sf::RectangleShape top_left({200.f, 100.f});
    //top_right
    sf::RectangleShape top_right({200.f, 100.f});
    top_right.setOrigin({200.f, 0.f});
    //bottom_left
    sf::RectangleShape bottom_left({200.f, 100.f});
    bottom_left.setOrigin({0.f, 100.f});
    //bottom_right
    sf::RectangleShape bottom_right({200.f, 100.f});
    bottom_right.setOrigin({200.f, 100.f});
    //top
    sf::RectangleShape top({200.f, 100.f});
    top.setOrigin({100.f, 0.f});
    //bottom
    sf::RectangleShape bottom({200.f, 100.f});
    bottom.setOrigin({100.f, 100.f});
    //left
    sf::RectangleShape left({200.f, 100.f});
    left.setOrigin({0.f, 50.f});
    //right
    sf::RectangleShape right({200.f, 100.f});
    right.setOrigin({200.f, 50.f});
    //center
    sf::RectangleShape center({200.f, 100.f});
    center.setOrigin({100.f, 50.f});
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
        //set position
        top_right.setPosition({window_w, 0.f});
        bottom_left.setPosition({0.f, window_h});
        bottom_right.setPosition({window_w, window_h});
        top.setPosition({window_w / 2, 0.f});
        bottom.setPosition({window_w / 2, window_h});
        left.setPosition({0.f, window_h / 2});
        right.setPosition({window_w, window_h / 2});
        center.setPosition({window_w / 2, window_h / 2});
        window.clear(sf::Color(100, 100, 100));
        
        //draw
        window.draw(top_left);
        window.draw(top_right);
        window.draw(bottom_left);
        window.draw(bottom_right);
        window.draw(top);
        window.draw(bottom);
        window.draw(left);
        window.draw(right);
        window.draw(center);

        window.display();

    }
    return 0;
}