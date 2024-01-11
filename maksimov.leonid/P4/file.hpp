#ifndef FILE_HPP
#define FILE_HPP
#include <string>
#include <iostream>

namespace file
{
  std::string readFile(std::ifstream&);
  void printToFile(std::ofstream&, const std::string&);
}

#endif
