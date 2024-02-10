#include <iostream>
#include "stringwork.hpp"

int main()
{
  std::cout << "ProgStart\n";
  char * str = new char [10000];
  yartsev::readstring(str);
  std::cout << str << "\n";
  delete [] str;
}