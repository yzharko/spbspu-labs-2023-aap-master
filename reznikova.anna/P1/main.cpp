#include <iostream>
#include <stdexcept>
#include "FindEqSeq.hpp"
using namespace reznikova;

int main()
{
  MaxEqualSequense maxEqualSequense;
  long long number = 0;
  do
  {
   std::cin >> number;
   if(!std::cin)
   {
     std::cerr << "Not a sequence.\n";
     return 1;
   }
   else if (number != 0)
   {
     try
     {
       maxEqualSequense(number);
     }
     catch (const std::exception & e)
     {
       std::cerr << "Error: " << e.what() << "\n";
       return 2;
     }
   }
  }
  while (number != 0);
  std::cout << maxEqualSequense() << "\n";
}
