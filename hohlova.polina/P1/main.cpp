#include <iostream>
#include <stdexcept>
#include <limits>
#include "Lessmore.hpp"
#include "findlocalmin.hpp"

int main()
{
  int prev = 0;
  int curr = 0;
  int next = 0;
  using namespace hohlova;
  using namespace hohlovaa;
  LessMore LessMore;
  FindLocalMin FindLocalMin;
  do
  {
    std::cin >> next;
    if (!std::cin)
    {
      std::cerr << "Not a sequence\n";
      return 1;
    }
    else if (next != 0)
    {
      try
      {
        LessMore(prev, curr, next);
        FindLocalMin(prev, curr, next);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
      prev = curr;
      curr = next;
    }
  }
  while (next != 0);
  std::cout << LessMore() << "\n";
  std::cout << FindLocalMin() << "\n";
}

