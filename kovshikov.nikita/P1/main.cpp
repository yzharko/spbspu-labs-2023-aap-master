#include <iostream>
#include "even_count.hpp"

int main()
{
  size_t num = 0;
  using namespace::kovshikov;
  EvenCount sequenceEven;
  do
  {
    std::cin >> num;
    if (!std::cin)
    {
      std::cerr << "Incorrect input\n";
      return 1;
    }
    else
    {
      if (num != 0)
      {
        try
        {
          sequenceEven(num);
        }
        catch (std::logic_error const& e)
        {
          std::cout << e.what() << "\n";
          return 1;
        }
      }
    }
  }
  while (num);
  std::cout << sequenceEven() << "\n";
  return 0;
}
