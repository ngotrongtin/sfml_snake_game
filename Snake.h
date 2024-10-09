#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

struct SnakeSegment {
    int x, y;
    SnakeSegment(int x, int y);
};

class Snake {
public:
    Snake();
    void move();
    void grow();
    void changeDirection(const sf::Vector2i& newDir);
    bool checkCollision();
    void draw(sf::RenderWindow& window);
    sf::Vector2i getHeadPosition();

private:
    std::vector<SnakeSegment> snake;
    sf::Vector2i direction;  // Hướng di chuyển
};