#include <iostream>
#include <stdexcept>
#include "sequenceCounter.hpp"

int main()
{
  SequenceCounter sequenceCounter{};
  int number;

  do
  {
    std::cin >> number;
    if (!std::cin)
    {
      std::cerr << "Could not read one or more of the numbers.\n";
      return 1;
    }
    try
    {
      sequenceCounter(number);
    }
    catch (const std::logic_error & e)
    {
      std::cerr << "Could not read a number. Details:\n" << e.what();
    }
  }
  while (number != 0);

  try
  {
    std::cout << sequenceCounter() << '\n';
  }
  catch (const std::logic_error & e)
  {
    std::cerr << "Could not calculate the number of pythagorean triples. Details:\n" << e.what() << '\n';
    return 2;
  }

  return 0;
}
