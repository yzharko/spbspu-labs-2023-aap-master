#ifndef main_hpp
#define main_hpp

#include <iosfwd>

class FindMaxEqualSequense
{
public:
  FindMaxEqualSequense() : count(0), max_count(0), previous_number(0) {}
  
  void operator()(long long number)
  {
    const long long maximum = std::numeric_limits< long long >::max();
    if (count <= maximum)
    {
      if (number == previous_number)
      {
        count++;
      }
      else if (count > max_count)
      {
        previous_number = number;
        max_count = count;
        count = 1;
      }
      else
      {
        previous_number = number;
        count = 1;
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

