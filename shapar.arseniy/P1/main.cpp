# include <iostream>
# include <limits>
# include <stdexcept>

struct SequenceCounter
{
public:
  void count_(int thirdNum)
  {
    const size_t maxSize = std::numeric_limits< size_t >::max();
    if (seqLen == maxSize)
    {
      throw std::logic_error("Sequence is too long.");
    }
    if (thirdNum == secondNum + firstNum)
    {
      ++count;
    }
    firstNum = secondNum;
    secondNum = thirdNum;
    ++seqLen;
  }

  size_t getResult() const
  {
    return count;
  }

private:
  size_t seqLen;
  int secondNum = 0;
  int firstNum = 0;
  int count = 0;
};

int main()
{
  int thirdNum;
  int secondNum = 0;
  int firstNum = 0;
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
        sequenceCounter.count_(thirdNum);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
      }
    }
  }
  while (thirdNum != 0);
  if (thirdNum == 0 && firstNum == 0)
  {
    std::cerr << "Not enough arguments.\n";
    return 2;
  }
  std::cout << sequenceCounter.getResult() << "\n";
}
