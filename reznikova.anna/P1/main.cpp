#include <iostream>
#include <stdexcept>
#include "FindEqSeq.hpp"
#include "FindDecSeq.hpp"

int main()
{
  using namespace reznikova;
  MaxEqualSequense maxEqualSequense;
  MaxDecreasingSequence maxDecreasingSequence;
  long long number = 0;
  do
  {
    std::cin >> number;
    if(!std::cin)
    {
      std::cerr << "Not a sequence.\n";
      return 1;
    }
    else if (number != 0)
    {
      try
      {
        maxEqualSequense(number);
        maxDecreasingSequence(number);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  }
  while (number != 0);
  std::cout << "maximum number of equal elements: ";
  std::cout << maxEqualSequense() << "\n";
  std::cout << "the largest length of a monotonically decreasing sequence: ";
  std::cout << maxDecreasingSequence() << "\n";
}
