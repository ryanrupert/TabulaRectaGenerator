/**
* Created by Ryan Rupert
* Date: 2017-03-03
* Source: None
* This program will generate a TabulaRecta
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

std::string value();
void line(int length);
//TODO: change the global variables to capitals
std::string values = "abcdefghijklmnopqrstuvwxyz0123456789()`~!@#$%^&*-+=|{}[]:;\"\'<>,.?/";
//TODO: change the global variables to capitals
void gen(int letter_range);
std::string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
void help();
void error();
void error(std::string msg);

int main(int argc, char** argv)
{
	srand(time(0));
	int letter_range = 0;
	bool rSet = false;

	//place the command argument code here
	for (int i = 0; i < argc; i++) 
	{
		if (!strcmp(argv[i], "-n")) 
		{
			rSet = true;
			i++;
			letter_range = atoi(argv[i]);
			if (letter_range <= 0) 
			{
				error("the number must be non-zero");
				return 1;
			}
		}
		else if (!strcmp[i], "-h" || !strcmp(argv[i], "--help"))
		{
			help();
			return 0;
		}
		else
		{
			error();
			return 1;
		}
	}

	std::cout << "How many letters and numbers would you like the table to have?"
	<< " Must be less than or equal to " << letters.length() << std::endl;
	std::cin >> letter_range;
	std::cin.get();

	std::cout << "Tabula Recta:" << std::endl;
	std::cout << std::endl;
	gen(letter_range);
	std::cin.get();
	return 0;
}

std::string value()
{
	std::string temp;
	int tempint;

	tempint = rand()%values.length();
	temp = values.at(tempint);
	return temp;
}

void line(int length)
{
	int index = 0;

	while(index < length)
	{
		std::cout << value() << "   ";
		index++;
	}
	std::cout << std::endl;
}

void gen(int letter_range)
{
	int index = 0;

	std::cout << "  |";
	while (letter_range > index) {
		std::cout << " " << letters.at(index) << " ";
		if(index >= letter_range)
			break;
		std::cout << "|";
		++index;
	}
	std::cout << std::endl;
	index = 0;
	while(letter_range > index)
	{
		std::cout << letters.at(index) << " | ";
		line(letter_range);
		++index;
	}
}

void help()
{
	std::cout << "usage: a [arguments]" << std::endl;
	std::cout << std::endl;
	std::cout << "arguments:" << std::endl;
	std::cout << "-n [number]		Generate table with the number given." << std::endl;
	std::cout << "-h, --help		Display help screen." << std::endl;
}

void error()
{
	std::cout << "argument not recognized." << std::endl;
	help();
}

void error(std::string msg)
{
	std::cout << msg << std::endl;
	help();
}
