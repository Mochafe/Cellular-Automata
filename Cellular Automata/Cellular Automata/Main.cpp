#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "App.h"


int main()
{
    int size{ 600 };
    sf::RenderWindow window(sf::VideoMode(size, size), "SFML works!", sf::Style::Titlebar | sf::Style::Close);
    
    App app(window);

    app.Loop();

    return 0;
}