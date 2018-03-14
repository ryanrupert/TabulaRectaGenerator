/**
* Created by Ryan Rupert
* Date: 2017-03-03
* Source: None
* This program will generate a tabularecta
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

std::string value();
void line(int length);
std::string values = "abcdefghijklmnopqrstuvwxyz0123456789()`~!@#$%^&*-+=|{}[]:;\"\'<>,.?/";
void gen(int letter_range);
std::string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

int main()
{
  srand(time(0));
  int letter_range = 0;
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
