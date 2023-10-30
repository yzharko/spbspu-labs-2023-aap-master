#include <iostream>
#include <limits>
#include <stdexcept>

struct SequenceCounter
{
public:
  SequenceCounter():
    seqLength_(0)
  {}

  void count(int number)
  {
     const size_t maxSize = std::numeric_limits< size_t >::max();
     if (seqLength_ == maxSize)
     {
       throw std::logic_error("Sequence is too long.");
     }
     ++seqLength_;
  }

  size_t getResult() const
  {
    return seqLength_;
  }

private:
  size_t seqLength_;
};

int main()
{
  int number = 0;
  SequenceCounter sequenceCounter;
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
       try
       {
         sequenceCounter.count(number);
       }
       catch (const std::exception & e)
       {
         std::cerr << "Error: " << e.what() << "\n";
       }
    }
  }
  while (number != 0);
  std::cout << sequenceCounter.getResult() << "\n";
}
