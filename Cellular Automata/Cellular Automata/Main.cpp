#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Time.h"


int main()
{
    int size{ 600 };
    sf::RenderWindow window(sf::VideoMode(size, size), "SFML works!", sf::Style::Titlebar | sf::Style::Close);
    sf::RectangleShape rect(sf::Vector2f(size / 60 , size / 60));
    rect.setFillColor(sf::Color::Green);
    rect.setPosition(sf::Vector2f((size / 2) - rect.getSize().x / 2, (size / 2) - rect.getSize().y / 2));
    sf::Vector2i mouse{};
    Time time;

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseMoved) {

                mouse = sf::Mouse::getPosition(window);

                //std::cout << "x: " << (float)mouse.x / width << ", y: " << (float)mouse.y / height << std::endl;

                rect.setPosition(sf::Vector2f(mouse.x - rect.getSize().x / 2, mouse.y - rect.getSize().y / 2));
            }
          
        }

        time.CalculateDeltaTime();
        
        std::cout << time.GetDeltaTime() << std::endl;

        window.clear();
        window.draw(rect);
        window.display();
    }

    return 0;
}