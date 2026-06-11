#include <SFML/Graphics.hpp>
#include <algorithm>
#include <cmath>
#include <iostream>

int main(){
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 4;
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML", sf::State::Windowed, settings);
    window.setKeyRepeatEnabled(false);

    sf::CircleShape circle;

    sf::RectangleShape rec;

    sf::RectangleShape line;

    sf::RectangleShape cursor;

    sf::RectangleShape grid;

    char state[3][3] ={
        {' ',' ', ' '},
        {' ',' ', ' '},
        {' ',' ', ' '}
    };

    bool turnO = 1;
    int cursor_x = 2;
    int cursor_y = 0;
    bool iswin = 0;

    auto Findposition = [&] (float c, float r, float width, int w, int h){
        width = std::min(w, h);
        return sf::Vector2f({width / 6 * (c * 2 + 1) + (w - width) / 2,
                             width / 6 * (r * 2 + 1) + (h - width) / 2});
    };
    auto Draw_O = [&] (sf::Vector2f pos, float width){
        float r = width * 0.8f;
        circle.setRadius(r);
        circle.setFillColor(sf::Color::Transparent);
        circle.setOutlineColor({38, 105, 217});
        circle.setOutlineThickness(0.1f * r);
        circle.setOrigin(circle.getGeometricCenter());
        circle.setPosition(pos);
        window.draw(circle);
    };

    auto Draw_X = [&] (sf::Vector2f pos, float width){
        float length = width * std::sqrt(2) * 0.8f;
        rec.setFillColor({232, 41, 13});
        rec.setSize({length, 0.05f * width});
        rec.setOrigin(rec.getGeometricCenter());
        rec.setPosition(pos);
        rec.setRotation(sf::degrees(45.f));
        window.draw(rec);
        rec.setRotation(sf::degrees(135.f));
        window.draw(rec);
    };

    auto Draw_WinningLine = [&] (sf::Vector2f pos, float length, float width, float angle){
        line.setFillColor({238, 245, 247});
        line.setSize({length, width});
        line.setOrigin(line.getGeometricCenter());
        line.setPosition(pos);
        line.setRotation(sf::degrees(angle));
        window.draw(line);
    };

    auto Draw_Cursor = [&] (int x, int y, float width){
        cursor.setOutlineColor({230, 242, 241});
        cursor.setFillColor(sf::Color::Transparent);
        cursor.setOutlineThickness(-0.01f * width);
        cursor.setSize({width * 0.95f, width * 0.95f});
        cursor.setOrigin(cursor.getGeometricCenter());
        cursor.setPosition(Findposition(x, y, width, window.getSize().x, window.getSize().y));
        window.draw(cursor);
    };

    auto Refresh = [&] (){
        iswin = 0;
        turnO = 1;
        cursor_x = 1;
        cursor_y = 1;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++)state[i][j] = ' ';
        }
    };

    auto Draw_Grid = [&](float width){
        grid.setFillColor(sf::Color::Transparent);
        grid.setOutlineColor({202, 244, 247});
        grid.setOutlineThickness(0.01f * width);
        grid.setSize({width * 1.05f, width * 1.05f});
        grid.setOrigin(grid.getGeometricCenter());
        grid.setPosition(Findposition(1, 1, width, window.getSize().x, window.getSize().y));
        window.draw(grid);

        grid.setOutlineThickness(0.f);
        grid.setFillColor({202, 244, 247});
        for(int i = 1; i <= 2; i++){
            grid.setSize({width * 1.05f, 0.01f * width});
            grid.setOrigin(grid.getGeometricCenter());
            grid.setPosition({width / 3 * i + (window.getSize().x - width) / 2, static_cast<float>(window.getSize().y) / 2});
            grid.setRotation(sf::degrees(90));
            window.draw(grid);
        }

        for(int i = 1; i <= 2; i++){
            grid.setSize({width * 1.05f, 0.01f * width});
            grid.setOrigin(grid.getGeometricCenter());
            grid.setPosition({static_cast<float>(window.getSize().x) / 2, width / 3 * i + (window.getSize().y - width) / 2});
            grid.setRotation(sf::degrees(0));
            window.draw(grid);
        }

    };
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
                if(iswin && key->scancode == sf::Keyboard::Scancode::Enter){
                    Refresh();
                }
                if(iswin)continue;
                if(key->scancode == sf::Keyboard::Scancode::Left && cursor_x > 0)cursor_x--;
                else if(key->scancode == sf::Keyboard::Scancode::Right && cursor_x < 2)cursor_x++;
                else if(key->scancode == sf::Keyboard::Scancode::Up && cursor_y > 0)cursor_y--;
                else if(key->scancode == sf::Keyboard::Scancode::Down && cursor_y < 2)cursor_y++;
                else if(key->scancode == sf::Keyboard::Scancode::Space && state[cursor_y][cursor_x] == ' '){
                    if(turnO)state[cursor_y][cursor_x] = 'O';
                    else state[cursor_y][cursor_x] = 'X';
                    turnO ^= 1;
                }
            }
        }
        
        float window_w = window.getSize().x;
        float window_h = window.getSize().y;
        float width = std::min(window_w, window_h) * 0.9f;

        window.clear({72, 81, 89});

        Draw_Grid(width);
        
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(state[i][j] == 'X'){
                    Draw_X(Findposition(j, i, width, window_w, window_h), width / 3);
                }
                else if(state[i][j] == 'O'){
                    Draw_O(Findposition(j, i, width, window_w, window_h), width / 6);
                }
            }
        }

        //winning line

        //horizontal line
        for(int i = 0; i < 3; i++){
            if(state[i][0] != ' ' && state[i][0] == state[i][1] && state[i][0] == state[i][2]){
                Draw_WinningLine(Findposition(1, i, width, window_w, window_h), width, width * 0.01f, 0.f);
                iswin = 1;
            }
        }
        //vertical line
        for(int j = 0; j < 3; j++){
            if(state[0][j] != ' ' && state[0][j] == state[1][j] && state[0][j] == state[2][j]){
                Draw_WinningLine(Findposition(j, 1, width, window_w, window_h), width, width * 0.01f, 90.f);
                iswin = 1;
            }
        }

        //diagonal line
        if(state[0][0] != ' '  && state[0][0] == state[1][1] && state[0][0] == state[2][2]){
            Draw_WinningLine(Findposition(1, 1, width, window_w, window_h), width * std::sqrt(2), width * 0.01f, 45.f);
            iswin = 1;
        }

        if(state[2][0] != ' '  && state[2][0] == state[1][1] && state[2][0] == state[0][2]){
            Draw_WinningLine(Findposition(1, 1, width, window_w, window_h), width * std::sqrt(2), width * 0.01f, 135.f);
            iswin = 1;
        }
        Draw_Cursor(cursor_x, cursor_y, width / 3);
        window.display();
    }
    return 0;
}