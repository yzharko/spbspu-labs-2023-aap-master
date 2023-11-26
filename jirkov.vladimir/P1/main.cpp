#include <iostream>
#include "findingCount.hpp"
int main()
{
  size_t value = 0;
  using namespace jirkov;
  FindingCount findingCount;
  do
  {
    std::cin >> value;
    if (!std::cin)
    {
      std::cerr << "Wrong input\n";
      return 1;
    }
    else if (value != 0)
    {
      findingCount(value);
    }
  }
  while (value != 0);
  try
  {
    std::cout << findingCount() << "\n";
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    return 2;
  }
}
