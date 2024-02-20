#include "transform.hpp"
#include <iostream>

int main() {
  std::string input;
  std::getline(std::cin, input);

  try {
    std::string result = transformString(input);
    std::cout << result << "\n";
    return 0;
    }
  catch (const std::bad_alloc& e)
    {
    std::cerr << "Error: Unable to allocate memory." << "\n";
    return 1;
    }
}
