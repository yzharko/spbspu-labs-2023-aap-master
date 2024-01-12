#include <iostream>
#include "functions.hpp"

int main()
{
  int answer = 0;
  try {
    answer = findSecondMax(std::cin);
  } catch (const std::exception & err) {
    std::cout << err.what() << "\n";
    return 2;
  }
  std::cout << answer << "\n";
  return 0;
}
