#include "App.h"
#include <iostream>

App::App(sf::RenderWindow &window) {
	
	time = Time();
	tick = Tick(20, time);
	grid = Grid(60);
	cellShape.reset(&grid.cellShape);
	this->window.reset(&window);
}


void App::Loop() {
	while (window.get()->isOpen()) {
		if (tick.isTick()) {
			(*cellShape.get()).clear();
			for (int i = 0; i < grid.actualBuffer.get()->size(); i++) {
				grid.ProcessCell(i);
			}
			for (auto shape : (*cellShape.get())) {
				window.get()->draw(shape);
			}


		}


		time.CalculateDeltaTime();

		sf::Event event;
		while (window.get()->pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.get()->close();

			if (event.type == sf::Event::MouseButtonPressed) {

				std::cout << "Click" << std::endl;
			}

		}

		window.get()->display();
		grid.SwapBuffer();
	}
}
