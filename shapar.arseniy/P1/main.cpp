# include <iostream>
# include <limits>

int main()
{
  int firstNum = 0;
  int secondNum = 0;
  int thirdNum = 0;
  int count = 0;
  size_t seqLen = 0;
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
      const size_t maxSize = std::numeric_limits< size_t >::max();
      if (seqLen == maxSize)
      {
        std::cerr << "Sequence is too long.\n";
        return 2;
      }
      if ( thirdNum == secondNum + firstNum)
       {
         ++count;
       }
       firstNum = secondNum;
       secondNum = thirdNum;
       ++seqLen;
    }
  }
  while (thirdNum != 0);
  if (seqLen == 1 || seqLen == 2 || seqLen == 3)
  {
    std::cerr << "Error";
  }
  std::cout << count << "\n";
}
