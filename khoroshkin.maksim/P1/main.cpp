#include <iostream>
#include <limits>
#include "findmax.hpp"

int main()
{
  khoroshkin::findMax countMax;
  int length = 0;
  try
  {
    int Value;
    std::cin.exceptions(std::istream::failbit);
    std::cin >> Value;
    while (Value != 0)
    {
      countMax(Value);
      length++;
      std::cin >> Value;
    }
    if (length == 0 && Value == 0)
    {
      throw std::logic_error("Error: not enough values");
    }
  }
  catch (const std::istream::failure & e)
  {
    std::cerr << "Error: only integer values";
    return 1;
  }
  catch (const std::logic_error & e)
  {
    std::cerr << e.what();
    return 2;
  }
  length > 2 ? std::cout << countMax() : std::cout << 0;
  return 0;
}
