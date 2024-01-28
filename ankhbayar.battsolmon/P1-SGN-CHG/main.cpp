#include <iostream>
#include "countSignChange.hpp"

int main()
{
  int number = 0;
  int seqLenght = 0;
  using namespace ankhbayar;
  CountSignChange countSignChange;

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
      ++seqLenght;
      try
      {
        countSignChange(number);
      }
      catch (const std::exception& e)
      {
        std::cerr << "Error:" << e.what() << "\n";
        return 2;
      }
    }
  }while (number != 0);

  if (seqLenght < 2)
  {
    std::cout << countSignChange() << "\n";
    std::cerr << "The sequence is too short.\n";
    return 2;
  }

  std::cout << countSignChange() << "\n";
  return 0;
}
