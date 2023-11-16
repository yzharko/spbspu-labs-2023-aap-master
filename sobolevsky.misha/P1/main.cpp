#include <iostream>
#include <exception>
#include "maxchetn.hpp"

int main()
{
  size_t countMax = 0;
  size_t counter = 0;
  size_t number;
  int quantity = 0;
  std::cin >> number;
  if (!std::cin)
    {
      std::cerr << "Enter only int\n";
      return 1;
    }
  while (number != 0)
  {
    counter = sobolevsky::maxChetn(counter, number);
    countMax = std::max(countMax, counter);
    quantity++;
    std::cin >> number;
    if (!std::cin)
    {
      std::cerr << "Enter only int\n";
      return 1;
    }
  }
  if (number == 0 && quantity == 0)
  {
    std::cerr << "Not enough values\n";
    return 2;
  }
  std::cout << countMax << "\n";
  return 0;
}
