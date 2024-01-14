#include "file.hpp"
#include <fstream>

std::string file::readFile(std::ifstream & file)
{
  std::string str = "";
  while (!file.eof())
  {
    std::string temp;
    file >> temp;
    str += temp;
  }
  return str;
}

void file::printToFile(std::ofstream & file, const std::string & text)
{
  file << text;
}
