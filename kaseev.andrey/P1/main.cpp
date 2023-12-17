#include "Divisibility.hpp"
#include <iostream>
#include <stdexcept>
#include <limits>

int main()
{
  kaseev::Divisibility Divisibility;
  try {
    int OldNum = 0, NewNum = 0;
    if (!(std::cin >> OldNum) || OldNum == 0)
    {
      throw std::logic_error("Wrong input");
    }
    if (!(std::cin >> NewNum))
    {
      throw std::logic_error("Wrong input");
    }
    if (OldNum == 0 || NewNum == 0)
    {
      throw std::logic_error("Not enough elements");
    }
    int ans = 0;
    ans = Divisibility(OldNum, NewNum);
    const int max_count = (std::numeric_limits<int>::max());
    if (ans > max_count)
    {
      throw std::overflow_error("Too many numbers");
    }
    Divisibility(ans);
    return 0;
  }
  catch (const std::logic_error &error)
  {
    std::cerr << error.what() << "\n";
    return 2;
  }
}
