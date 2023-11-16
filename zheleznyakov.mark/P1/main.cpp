#include <iostream>
#include <exception>
#include "seqCounter.hpp"

int main()
{
  zheleznyakov::SequenceCounter sequenceCounter;
  try
  {
    std::cin.exceptions(std::istream::failbit);
    int element = 0;
    do
    {
      std::cin >> element;
      sequenceCounter(element);
    }
    while (element != 0);
  }
  catch (const std::istream::failure & e)
  {
    std::cerr << "Error: only valid integers are accepted\n";
    return 1;
  }
  catch (const std::logic_error & e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
  std::cout << sequenceCounter() << '\n';
  return 0;
}
