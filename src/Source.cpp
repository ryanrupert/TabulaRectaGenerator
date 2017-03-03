#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

std::string value();
std::string values = "abcdefghijklmnopqrstuvwxyz0123456789()`~!@#$%^&*-+=|{}[]:;\"\'<>,.?/";

int main()
{
  srand(time(0));
  std::cout << "Tabula Recta:" << std::endl;
  std::cout << std::endl;
  std::cout << "  | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | X | Y | Z" << std::endl;
  std::cout << "  ---------------------------------------------------------------------------------------------------" << std::endl;
  std::cout << "A | " << value() << " " << value() << " " << value() << " " << value() << " " << value() << " " << value() << " " << value() << " " << value() << " " << value() << " " << value() << std::endl;
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
