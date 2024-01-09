#include <iostream>
#include <cctype>
#include <string>
#include "function.hpp"

int main() {
  std::string input;
  std::getline(std::cin, input);
  try 
  {
    std::string result = CreateString(input);
    std::cout << result << std::endl;
  }
  catch (const std::bad_alloc& e) 
  {
    std::cerr << "Error\n";
    return 1;
  }
  return 0;
}
