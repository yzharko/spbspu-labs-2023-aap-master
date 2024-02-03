#include <iostream>
#include <typeinfo>
#include "Counter.hpp"

int main()
{
  int number = -1;
  int seqCounter = 0;
  using namespace mihalchenko;

  CounterAfterMax counterAfterMax;
  while (number != 0)
  {
    std::cin >> number;
    if (!std::cin)
    {
      std::cerr << "Not a sequence.\n";
      return 1;
    }
    else if (number != 0)
    {
      seqCounter++;
      try
      {
        counterAfterMax(number, seqCounter);
      }
      catch (const std::exception& e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  }
  std::cout << counterAfterMax(seqCounter) << "\n";
  return 0;
}
