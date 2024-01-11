#include <iostream>
#include <stdexcept>
#include "findCount.hpp"
#include "evenNumber.hpp"

int main()
{
  size_t value = 0;
  using namespace gorbunova;
  FindCount findCount;
  EvenNumber evenNumber;
  do
  {
    std::cin >> value;
    if (!std::cin)
    {
      std::cerr << "Not a sequence\n";
      return 1;
    }
    else if (value != 0)
    {
      try
      {
        findCount(value);
        evenNumber(value);
      }
      catch (const std::logic_error & e)
      {
       std::cerr << "Error: " << e.what() << "\n";
       return 2;
      }
    }
  }
  while (value != 0);
  std::cout << findCount() << "\n";
  std::cout << evenNumber() << "\n";
  return 0;
}
