#include <iostream>
#include <cmath>
#include <limits>
#include <exception>
namespace seryj
{
  void findMaxCount(bool condition, int& count, int& max_count)
  {
    count = condition ? count + 1 : 1;
    max_count = fmax(max_count, count);
  }

  int read()
  {
    const int max_limit = std::numeric_limits< int >::max();
    const int min_limit = std::numeric_limits< int >::min();
    auto val = 0.0;
    std::cin >> val;
    if (val != static_cast< int >(val))
      throw std::logic_error("No float, please");
    if (val > max_limit || val < min_limit)
      throw std::overflow_error("Owerflow");
    std::cin.exceptions(std::istream::failbit);
    return val;
  }
}
