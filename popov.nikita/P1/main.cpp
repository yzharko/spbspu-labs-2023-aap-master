#include <iostream>
#include <stdexcept>
#include "counter_minimums.hpp"

int main()
{
  using namespace popov;
  CountMinSt CountMin;
  int number = 0;
  do
  {
    std::cin >> number;
    if (!std::cin)
    {
      std::cerr << "not a number\n";
      return 1;
    }
    if (number != 0)
    {
      try
      {
        CountMin(number);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
      }
    }
  }
  while (number != 0);
  std::cout << CountMin() << "\n";
  return 0;
}
