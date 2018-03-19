/**
* Created by Ryan Rupert
* Date: 2017-03-03
* Source: None
* This program will generate a TabulaRecta
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <fstream>

#define output(msg) outputf(writeFile, suppress, msg)

std::string value();
void line(bool writeFile, bool suppress, int length);
//TODO: change the global variables to capitals
std::string values = "abcdefghijklmnopqrstuvwxyz0123456789()`~!@#$%^&*-+=|{}[]:;\"\'<>,.?/";
//TODO: change the global variables to capitals
void gen(bool writeFile, bool suppress, int letter_range);
std::string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

void help();
void error();
void error(std::string msg);

template <typename T>
void outputf(bool sendFile, bool suppress, T msg);
std::ofstream out;
bool openFile(std::string file);
void closeFile();

int main(int argc, char** argv)
{
	srand(time(0));
	int letter_range = 0;
	bool rSet = false;
	bool writeFile = false;
	bool suppress = false;
	std::string file;

	//place the command argument code here
	for (int i = 1; i < argc; i++) 
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
		else if (!strcmp(argv[i], "-f") || !strcmp(argv[i], "--file"))
		{
			writeFile = true;
			i++;
			file = argv[i];

			if (!openFile(file)) 
			{
				error("the file could not be opened");
				return 1;
			}
		}
		else if (!strcmp(argv[i], "-s"))
		{
			suppress = true;
		}
		else if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help"))
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
	if (!writeFile && suppress) 
	{
		error("suppress can only be used when writing to a file");
		if (writeFile) 
		{
			closeFile();
		}
		return 1;
	}

	if (!rSet) 
	{
		std::cout << "How many letters and numbers would you like the table to have?"
		<< " Must be less than or equal to " << letters.length() << std::endl;
		std::cin >> letter_range;
		std::cin.get();
	}

	output("Tabula Recta:");
	output("\n");
	gen(writeFile, suppress, letter_range);
	if (writeFile) 
	{
		std::cin.get();
	}
	closeFile();
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

void line(bool writeFile, bool suppress, int length)
{
	int index = 0;

	while(index < length)
	{
		output(value());
		output("   ");
		index++;
	}
	output("\n");
}

void gen(bool writeFile, bool suppress, int letter_range)
{
	int index = 0;

	output("  |");
	while (letter_range > index) {
		output(" ");
		output(letters.at(index));
		output(" ");
		if(index >= letter_range)
			break;
		output("|");
		++index;
	}
	output("\n");
	index = 0;
	while(letter_range > index)
	{
		output(letters.at(index));
		output(" | ");
		line(writeFile, suppress, letter_range);
		++index;
	}
}

void help()
{
	std::cout << "usage: a [arguments]" << std::endl;
	std::cout << std::endl;
	std::cout << "arguments:" << std::endl;
	std::cout << "-n [number]		Generate table with the number given." << std::endl;
	std::cout << "-f, --file [file name]	Write the table to file." << std::endl;
	std::cout << "-s			Suppress output." << std::endl;
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

template <typename T>
void outputf(bool sendFile, bool suppress, T msg)
{
	if (!sendFile) 
	{
		std::cout << msg;
	}
	else if (sendFile && !suppress)
	{
		out << msg;
		std::cout << msg;
	}
	else if (sendFile && suppress)
	{
		out << msg;
	}
}

bool openFile(std::string file)
{
	out.open(file.c_str());
	if (!out) 
	{
		return false;
	}
	return true;
}

void closeFile()
{
	out.close();
}
