#include <iostream>
#include <limits>

int main()
{
  int number = 0;
  size_t seqLength = 0;
  do
  {
    std::cin >> number;
    if (!std::cin)
    {
      std::cerr << "Not a sequence.\n";
      return 1;
    }
    else if (number != 0)
    {
       const size_t maxSize = std::numeric_limits< size_t >::max();
       if (seqLength == maxSize)
       {
         std::cerr << "Sequence is too long.\n";
         return 2;
       }
       ++seqLength;
    }
  }
  while (number != 0);
  std::cout << seqLength << "\n";
}
