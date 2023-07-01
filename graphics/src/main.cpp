
#include <iostream>
#include <vector>

#include <chrono>
#include <thread>

#include <iostream>
#include <vector>

#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>
#include <windows.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(300, 100), "Memory load");

    std::vector<sf::Vertex> vertices;

    MEMORYSTATUSEX mem;
    mem.dwLength = sizeof(mem);

    unsigned step = 0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        GlobalMemoryStatusEx(&mem);

        if (vertices.size() < window.getSize().x) {
            vertices.push_back(sf::Vertex(sf::Vector2f(step, mem.dwMemoryLoad)));
        } else {
            vertices.clear();
            step = 0;
        }

        window.clear();

        if (vertices.size() > 0) {
            window.draw(&vertices[0], vertices.size(), sf::LineStrip);
        }

        window.display();
        step++;
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
}
// int main()
// {
//     sf::ContextSettings contextSettings;
//     contextSettings.antialiasingLevel = 16;

//     sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window", sf::Style::Default, contextSettings);

//     sf::CircleShape shape(100);
//     sf::Clock clock;
//     sf::Time dt;

//     sf::Texture texture;

//     shape.setFillColor(sf::Color(155, 89, 182));
//     shape.setTexture(&texture);
//     shape.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
//     shape.setOrigin(sf::Vector2f(shape.getRadius(), shape.getRadius()));

//     float speed = 100;

//     while (window.isOpen()) {
//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed) {
//                 window.close();
//             }
//         }

//         if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
//             shape.move(sf::Vector2f(0, -speed) * dt.asSeconds());
//         }
//         if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
//             shape.move(sf::Vector2f(-speed, 0) * dt.asSeconds());
//         }
//         if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
//             shape.move(sf::Vector2f(0, speed) * dt.asSeconds());
//         }
//         if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
//             shape.move(sf::Vector2f(speed, 0) * dt.asSeconds());
//         }

//         if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {
//             if ((int)speed < 1000) {
//                 speed += 100;
//             }
//         }
//         if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
//             if ((int)speed > 100) {
//                 speed -= 100;
//             }
//         }

//         window.clear();
//         window.draw(shape);
//         window.display();
//         dt = clock.restart();
//     }

//     return 0;
// }