#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>


int h = 512;
int w = 512;

sf::RenderWindow window(sf::VideoMode(h, w), "SFML Test", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);

int randomnumber()
{
	int randnum = rand() % 500 + 10;

	return randnum;
}


void draw_bars()
{

	//create bars with random height



	double barposh, barposw;
	int barh, barw;

	barw = 20;
	//barh = rand() % 500 + 1;

	//barposh = h - barh;				//makes sure bars are drawn an bottom edge of window
	barposw = 5;

	int barnum = 10;


	window.clear(sf::Color::Black);

	//sf::RectangleShape bar(sf::Vector2f(barw, barh));

	for (int i = 0; i < barnum; i++)
	{
		barh = randomnumber();

		sf::RectangleShape bars_array[10];

		sf::RectangleShape bar(sf::Vector2f(barw, barh));

		bars_array[i] = bar;

		barposh = h - barh;													//makes sure bars are drawn an bottom edge of window

		bar.setPosition(barposw, barposh);

		bar.setFillColor(sf::Color(100, 150, 50));

		window.draw(bar);

		barposw = barposw + barw + 30;

	}

	
	window.display();

}




int main()
{

	draw_bars();



	while (window.isOpen())
	{



		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			
			case sf::Event::Resized:
				std::cout << "New window width: " << evnt.size.height <<" New window height: " << evnt.size.width << std::endl;
				break;

			case sf::Event::KeyPressed:
				if (evnt.key.code == sf::Keyboard::S)
				{
					//sort();
				}
				
			}
			/*
			if (evnt.type == evnt.Closed) {

				window.close();
			} */




		}
	


	}

    return 0;
}