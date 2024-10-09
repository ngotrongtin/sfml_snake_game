#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Food.h"
#include <iostream>
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake Game");
    Snake snake;
    Food food;

    sf::Clock clock;
    float moveDelay = 0.2f;
    float elapsedTime = 0.0f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Điều khiển rắn
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            snake.changeDirection(sf::Vector2i(0, -1));
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            snake.changeDirection(sf::Vector2i(0, 1));
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            snake.changeDirection(sf::Vector2i(-1, 0));
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            snake.changeDirection(sf::Vector2i(1, 0));
        }

        // Di chuyển rắn theo thời gian
        elapsedTime += clock.restart().asSeconds();
        if (elapsedTime >= moveDelay) {
            snake.move();

            // Kiểm tra nếu rắn ăn thức ăn
            if (snake.getHeadPosition() == food.getPosition()) {
                snake.grow();
                food.spawn();
            }

            // Kiểm tra nếu rắn va chạm
            if (snake.checkCollision()) {
                std::cout << "Game Over!" << std::endl;
                window.close();
            }

            elapsedTime = 0.0f;
        }

        // Vẽ rắn và thức ăn
        window.clear();
        snake.draw(window);
        food.draw(window);
        window.display();
    }

    return 0;
}
