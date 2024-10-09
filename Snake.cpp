#include "Snake.h"
#include <SFML/Graphics.hpp>

SnakeSegment::SnakeSegment(int x, int y) : x(x), y(y) {}

Snake::Snake() {
    snake.emplace_back(5, 5);
    direction = sf::Vector2i(1, 0);
}

void Snake::move() {
    for (int i = snake.size() - 1; i > 0; --i) {
        snake[i] = snake[i - 1];
    }
    snake[0].x += direction.x;
    snake[0].y += direction.y;
}

void Snake::grow() {
    snake.push_back(snake.back());
}

void Snake::changeDirection(const sf::Vector2i& newDir) {
    if (direction.x != -newDir.x && direction.y != -newDir.y) {
        direction = newDir;
    }
}

bool Snake::checkCollision() {
    if (snake[0].x < 0 || snake[0].x >= 800/20|| snake[0].y < 0 || snake[0].y >= 600/20) {
        return true;
    }
    for (int i = 3; i < snake.size(); ++i) {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
            return true;
        }
    }
    return false;
}

void Snake::draw(sf::RenderWindow& window) {
    sf::RectangleShape segmentShape(sf::Vector2f(20 - 1, 20 - 1));
    segmentShape.setFillColor(sf::Color::Green);
    for (auto& segment : snake) {
        segmentShape.setPosition(segment.x * 20, segment.y * 20);
        window.draw(segmentShape);
    }
}

sf::Vector2i Snake::getHeadPosition() {
    return sf::Vector2i(snake[0].x, snake[0].y);
}
