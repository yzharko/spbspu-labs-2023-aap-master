#include <iostream>
#include "stringwork.hpp"

int main()
{
  std::cout << "ProgStart\n";
  char * str = new char [10000];
  try {
    yartsev::readstring(str);
  } catch (std::logic_error & e) {
    std::cerr << e.what() << "\n";
    return 2;
  }
  std::cout << str << "\n";
  delete [] str;
}