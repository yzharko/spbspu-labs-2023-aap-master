#include <iostream>
#include "main.hpp"

int main()
{
  FindMaxEqualSequense findMaxEqualSequense;
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
       findMaxEqualSequense(number);
     }
     catch (const std::overflow_error & e)
     {
       std::cerr << "Error: " << e.what() << "\n";
       return 2;
     }
   }
  }
  while (number != 0);
  std::cout << findMaxEqualSequense.maxEqualSecuence() << "\n";
}

