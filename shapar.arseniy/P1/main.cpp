#include <iostream>
#include <exception>
#include <cstddef>
#include "GRT_LSS.hpp"
#include "SUM_DUP.hpp"

int main()
{
  size_t thirdNum = 0;
  using namespace shapar;
  SumdupCounter sumdupCounter;
  GrtlssCounter grtlssCounter;
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
        sumdupCounter(thirdNum);
        grtlssCounter(thirdNum);
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
  std::cout << sumdupCounter() << "\n";
  std::cout << "GRT_LSS: ";
  std::cout << grtlssCounter() << "\n";
}
