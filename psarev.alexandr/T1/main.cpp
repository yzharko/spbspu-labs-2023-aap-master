#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include "rectangle.hpp"
#include "ring.hpp"
#include "triangle.hpp"

int main()
{
  std::string keyWord = "";
  std::vector<double> rectData(4);
  std::vector<double> ringData(4);
  std::vector<double> trianData(6);
  char* queue = new char[3] {};
  bool scaleMark = false;
  bool errMark = false;
  size_t figIndex = 0;

  
  if (!scaleMark) {
    std::cerr << "Error: Scale command is missing or incorrect!\n";
    delete[] queue;
    return 1;
  }
  if (errMark) {
    std::cerr << "Error: One or more supported shapes are not specified correctly!\n";
  }
  delete[] queue;
  return 0;
}
