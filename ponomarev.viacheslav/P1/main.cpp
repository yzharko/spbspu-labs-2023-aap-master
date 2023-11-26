#include <iostream>
#include "seqCounter.hpp"

int main()
{
  int number = 0;
  using namespace ponomarev;
  SequenceCounter sequenceCounter;
  do
  {
    std::cin >> number;
    if (!std::cin)
    {
      std::cerr << "Not a sequence.\n";
      return 1;
    }
    else if (number != 0)
    {
      try
      {
        sequenceCounter(number);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  }
  while (number != 0);
  std::cout << sequenceCounter() << "\n";
}
