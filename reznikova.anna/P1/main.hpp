#ifndef main_hpp
#define main_hpp
#include <iosfwd>
#include <limits>
#include <stdexcept>

class FindMaxEqualSequense
{
public:
  FindMaxEqualSequense() : count(1), max_count(0), previous_number(0) {}
  void operator()(long long number)
  {
    const long long maximum = std::numeric_limits< long long >::max();
    if (count <= maximum)
    {
      if (number != previous_number)
      {
        previous_number = number;
        count = 1;
      }
      else
      {
        count++;
      }
      if (count > max_count)
      {
        max_count = count;
      }
    }
    else
    {
      throw std::overflow_error("Too many sequence elements");
    }
  }
  long long maxEqualSecuence()
  {
    return max_count;
  }
private:
  long long count;
  long long max_count;
  long long previous_number;
};

#endif

