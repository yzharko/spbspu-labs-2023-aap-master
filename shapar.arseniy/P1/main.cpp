#include <iostream>
#include <exception>
#include <cstddef>
#include "var1.hpp"

int main()
{
  size_t thirdNum = 0;
  int fourthNum_ = 0;
  using namespace shapar;
  SequenceCounter sequenceCounter;
  do
  {
    std::cin >> thirdNum;
    if (!std::cin)
    {
      std::cerr << "Not a sequence.\n";
      return 1;
    }
    else if (thirdNum != 0)
    {
      try
      {
        sequenceCounter(thirdNum);
      }
      catch (const std::logic_error & e)
      {
        std::cerr << e.what();
        return 2;
      }
      catch (const std::istream::failure & e)
      {
        std::cerr << "Not a sequence";
        return 1;
      }
      catch (const std::overflow_error & e)
      {
        std::cerr << e.what();
        return 1;
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  }
  while (thirdNum != 0);
  std::cout << sequenceCounter() << "\n";
}
