

#include <iostream>
#include <exception>
#include <cstddef>
#include "var1.hpp"
#include "var2.hpp"

int main()
{
  size_t thirdNum;
  int fourthNum_;
  using namespace shapar;
  using namespace shaparr;
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
  SequenceCounter_ sequenceCounter_;
  do
  {
    std::cin >> fourthNum_;
    if (!std::cin)
    {
      std::cerr << "Not a sequence.\n";
      return 1;
    }
    else if (fourthNum_ != 0)
    {
      try
      {
        sequenceCounter_(fourthNum_);
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
        return  2;
      }
    }
  }
  while (fourthNum_ != 0);
  std::cout << sequenceCounter_() << "\n";
}
