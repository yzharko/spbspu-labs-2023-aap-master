#include "CountMinSequence.hpp"
#include <iostream>

using namespace nikiforov;

int main()
{
  try
  {
    int num = 0;
    size_t lenth = 0;
    Sequence arrMin;
    do
    {
      std::cin >> num;
      if (!std::cin)
      {
        std::cerr << "Wrong Input\n";
        return 1;
      }
      arrMin(num);
      lenth++;
    } while (num != 0);

    if (lenth == 1) {
      throw std::overflow_error("Too short sequence\n");
    }

    size_t result = arrMin();
    std::cout << result;
  }
  catch (const std::overflow_error& e)
  {
    std::cout << e.what() << "\n";
    return 2;
  }
  return 0;
}
