#include <iostream>
#include <exception>
#include <cstddef>
#include "var2.hpp"
#include "var1.hpp"

int main()
{
  size_t thirdNum = 0;
  using namespace shapar;
  SequenceCounter sequenceCounter;
  SequenceCounter_ sequenceCounter_;
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
        sequenceCounter_(thirdNum);
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
  std::cout << "SUM_DUM: ";
  std::cout << sequenceCounter() << "\n";
  std::cout << "GRT_LSS: ";
  std::cout << sequenceCounter_() << "\n";
}
