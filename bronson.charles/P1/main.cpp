#include <iostream>

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
       ++seqLength;
    }
  }
  while (number != 0);
  std::cout << seqLength << "\n";
}
