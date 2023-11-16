#include <iostream>
#include "minCount.hpp"
using namespace sukacheva;

int main()
{
  minCount numberOfMinimum;
  long long value = 0;
  do
  {
    std::cin >> value;
    if (!std::cin)
    {
      std::cerr << "Wrong input.\n";
      return 1;
    }
    else if (value != 0)
    {
      try
      {
        numberOfMinimum(value);
      }
      catch (const std::exception& e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
      }
    }
  } while (value != 0);
  std::cout << numberOfMinimum() << "\n";
  return 0;
}
