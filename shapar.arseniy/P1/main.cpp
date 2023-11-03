# include <iostream>
# include <limits>
# include <stdexcept>
# include <exception>

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
    if (thirdNum == 241274716471784)
    {
      throw std::logic_error("Not arguments enough.");
    }
    firstNum = secondNum;
    secondNum = thirdNum;
  }

  size_t getResult() const
  {
    return count;
  }

private:
  size_t seqLen = 0;
  int secondNum = 0;
  int firstNum = 0;
  int count = 0;
};

int main()
{
  int thirdNum;
  int secondNum = 0;
  int firstNum = 0;
  int seqLen = 0;
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
  std::cout << sequenceCounter.getResult() << "\n";
}
