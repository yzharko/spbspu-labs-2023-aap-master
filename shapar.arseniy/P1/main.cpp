# include <iostream>
# include <stdexcept>
# include <exception>
#include "var1.hpp"

int main()
{
  int seqLen = 0;
  int thirdNum;
  using namespace shapar;
  SequenceCounter sequenceCounter;
  do
  { 
    ++seqLen;
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
      }
    } 
  }
  while (thirdNum != 0);
  if (seqLen <= 3)
  {
    std::cerr<<"Not enough arguments";
    return 2;
  }
  std::cout << sequenceCounter() << "\n";
}
