#include "Funcs.hpp"
#include <iostream>
#include <cmath>
#include <exception>

int main()
{
  int count = 1;
  int max_count = 0;
  int last_value = 0;
  int current_value = 0;
  try
  {
    last_value = seryj::read();
    while (last_value && std::cin)
    {
      current_value = seryj::read();
      seryj::findMaxCount(last_value == current_value, count, max_count);
      last_value = current_value;
    }
    std::cout << "Result: " << max_count << "\n";
    return 0;
  }
  catch (const std::overflow_error & e)
  {
    std::cerr << e.what();
    return 1;
  }
  catch (const std::istream::failure & e)
  {
    std::cerr << "Input error";
    return 1;
  }
  catch (const std::logic_error& e)
  {
    std::cerr << e.what();
    return 1;
  }
}
