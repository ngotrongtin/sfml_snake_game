#pragma once
#include <SFML/Graphics.hpp>

class Food {
public:
    Food();
    void spawn();
    void draw(sf::RenderWindow& window);
    sf::Vector2i getPosition();

private:
    sf::RectangleShape foodShape;
    sf::Vector2i position;
};


