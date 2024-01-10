#include <iostream>
#include "neostring.hpp"
#include "transformations.hpp"


int main()
{
  char* string = nullptr;
  if (miheev::readString(&string, std::cin) == 0)
  {
    std::cerr << "you've entered an empty line\n";
    delete[] string;
    return 1;
  }
  std::cout << miheev::countDiffLat(string) << '\n';
  delete[] string;
  return 0;
}
