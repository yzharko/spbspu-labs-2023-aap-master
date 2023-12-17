#include "count.hpp"
#include <iostream>

int main()
{
  size_t value = 0;
  using namespace tsomo;
  FindingCount findingCount;

  do
  {
    std::cin >> value;

    if (!std::cin)
    {
      std::cerr << "Неверный ввод\n";
      return 1;
    }
    else if (value != 0)
    {
      findingCount(value);
    }
  } while (value != 0);

  try
  {
    std::cout << findingCount() << "\n";
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    return 2;
  }

  return 0;
}
