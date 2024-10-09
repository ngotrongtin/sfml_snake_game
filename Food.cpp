#include "Food.h"
#include <cstdlib>

Food::Food() {
    foodShape.setSize(sf::Vector2f(20 - 1, 20 - 1));
    foodShape.setFillColor(sf::Color::Red);
    spawn();
}

void Food::spawn() {
    int maxX = 800 / 20;
    int maxY = 600 / 20;
    position = sf::Vector2i(rand() % maxX, rand() % maxY);
    foodShape.setPosition(position.x * 20, position.y * 20);
}

void Food::draw(sf::RenderWindow& window) {
    window.draw(foodShape);
}

sf::Vector2i Food::getPosition() {
    return position;
}
