#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

std::string value();
void line(int length);
std::string values = "abcdefghijklmnopqrstuvwxyz0123456789()`~!@#$%^&*-+=|{}[]:;\"\'<>,.?/";

int main()
{
  srand(time(0));
  std::cout << "Tabula Recta:" << std::endl;
  std::cout << std::endl;
  std::cout << "  | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z" << std::endl;
  std::cout << "---------------------------------------------------------------------------------------------------------" << std::endl;
  std::cout << "A | ";
  line(26);
  std::cout << "B | ";
  line(26);
  std::cout << "C | ";
  line(26);
  std::cout << "D | ";
  line(26);
  std::cout << "E | ";
  line(26);
  std::cout << "F | ";
  line(26);
  std::cout << "G | ";
  line(26);
  std::cout << "H | ";
  line(26);
  std::cout << "I | ";
  line(26);
  std::cout << "J | ";
  line(26);
  std::cout << "K | ";
  line(26);
  std::cout << "L | ";
  line(26);
  std::cout << "M | ";
  line(26);
  std::cout << "N | ";
  line(26);
  std::cout << "O | ";
  line(26);
  std::cout << "P | ";
  line(26);
  std::cout << "Q | ";
  line(26);
  std::cout << "R | ";
  line(26);
  std::cout << "S | ";
  line(26);
  std::cout << "T | ";
  line(26);
  std::cout << "U | ";
  line(26);
  std::cout << "V | ";
  line(26);
  std::cout << "W | ";
  line(26);
  std::cout << "X | ";
  line(26);
  std::cout << "Y | ";
  line(26);
  std::cout << "Z | ";
  line(26);
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
