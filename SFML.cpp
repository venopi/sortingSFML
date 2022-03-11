#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <ctime>

int h = 700;
int w = 1280;

sf::RenderWindow window(sf::VideoMode(w, h), "SFML Test", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);

int randomnumber()
{

	int randnum = rand() % 700 + 10;

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

	barw = 3;

	barposw = 5;
	
	int barnum = size;

	int gap_between_bars = 1;

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
		{
			
			return 0;									//sort fail
		}

		else if (i == (size - 1))
		{

			return 1;									//sort success
		}
	}

}

int main()
{

	srand(time(0));

	int success = 0;

	int* sorted_arr;

	int size;

	int checked = 0;

	int temp = 0;

	std::cout << "Wieviele Saeulen?" << std::endl;
	std::cin >> size;
	while (size <= 1 || size > 32500)
	{
		std::cout << "Ungueltige Eingabe. Versuche eine Zahl zwischen 2 und 32500 zu waehlen!" << std::endl << std::endl;
		std::cout << "Wieviele Saeulen?" << std::endl;
		std::cin >> size;
	}

	int* arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		arr[i] = randomnumber();
	}

	draw_bars(arr, size);

	sorted_arr = sort(arr, size);

	printarray(sorted_arr, size);

	check(sorted_arr, size);

	while (window.isOpen())
	{
		

			/// ///										while loop war voher in main
	
		if (checked != 1 && check(sorted_arr, size) == 0 )
		{

			sort(sorted_arr, size);

			draw_bars(sorted_arr, size);
		}

		else if (temp > 10)
		{
			goto jmp;

		}

		else 
		{
			checked = 1;
			std::cout << "Success" << std::endl;
			temp = temp + 1;
		}

			
			/// ///

	jmp:

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
					draw_bars(sorted_arr, size);
				}
				
			}


		}
	


	}



    return 0;
}