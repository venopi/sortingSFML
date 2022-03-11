#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <ctime>

int h = 512;
int w = 512;

sf::RenderWindow window(sf::VideoMode(h, w), "SFML Test", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);

int randomnumber()
{

	int randnum = rand() % 500 + 10;

	return randnum;
}

void printarray(int * arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout<< "#"<< i <<"#________" << arr[i] << std::endl;
	}
}


int draw_bars(int * arr, int size)
{
	printarray(arr, size);
	//draw bars with random height. Height will be taken from an array of random numbers
	
	double barposh, barposw;
	int barh, barw;

	barw = 10;

	barposw = 5;
	
	int barnum = size;

	int gap_between_bars = 5;

	window.clear(sf::Color::Black);

	for (int i = 0; i < barnum; i++)
	{
		barh = arr[i];

		sf::RectangleShape bar(sf::Vector2f(barw, barh));

		arr[i] = barh;

		barposh = h - barh;									//makes sure bars are drawn an bottom edge of window

		bar.setPosition(barposw, barposh);

		bar.setFillColor(sf::Color(100, 150, 50));

		window.draw(bar);

		barposw = barposw + barw + gap_between_bars;


	}

	
	window.display();

	return 0;										//an array with the heights of the bars gets returned
}



int * sort(int * array, int size)
{	
	int *copiedarray;
	copiedarray = array;

	for (int i = 0; i < size; i++)
	{
		if (i == (size-1))
		{
			std::cout << "sorted" << std::endl;
			return array;
			
		}
		else if (array[i] > array[i+1])
		{

			int temp;
			temp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = temp;

		}
		
	}

	
}




int check(int * array, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout <<"_______________________" << array[i] << std::endl;

		

			if (array[i] > array[i + 1] && i != (size - 1)) 
				return 0;									//sort fail

			else if (i == (size - 1))
				return 1;									//sort success

	}

}

int main()
{
	srand(time(0));

	int* sorted_arr;

	int arr[30];
	
	for (int i = 0; i < 30; i++)
	{
		arr[i] = randomnumber();
	}

	draw_bars(arr, 30);

	sorted_arr = sort(arr, 30);

	printarray(sorted_arr, 30); 

	check(sorted_arr, 30);

	while (check(sorted_arr, 30) == 0)
	{
		sort(sorted_arr, 30);
	}

	std::cout << "Success" << std::endl;

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
					draw_bars(sorted_arr, 30);
				}
				
			}





		}
	


	}



    return 0;
}