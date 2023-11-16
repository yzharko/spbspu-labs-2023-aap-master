#include <iostream>
#include <stdexcept>
#include "seqCounter.hpp"

int main()
{
  int value = 0;
  using namespace tellez;
  LongestDecreasingCounter counter;
  do
  {
    std::cin >> value;
    if (!std::cin)
    {
      std::cerr << "Not a valid input. Exiting...\n";
      return 1;
    }
    else if (value != 0)
    {
      try
      {
        counter.processValue(value);
      }
      catch (const std::exception &e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  }
  while (value != 0);
  std::cout << "Longest decreasing found: " << counter.getLongestSequenceLength() << "\n";
  return 0;
}
