
#include <iostream>
#include <exception>
#include "seqCounter.hpp"

int main()
{
  rejepbayev::jasur::SequenceCounter sequenceCounter;
  try
  {
    std::cin.exceptions(std::istream::failbit);
    int inputNumber = 0;

    do
    {
      std::cin >> inputNumber;
      sequenceCounter(inputNumber);
    }
    while (inputNumber != 0);
  }
  catch (const std::istream::failure&)
  {
    std::cerr << "Input Error: Please enter valid integers only.
";
    return 1;
  }
  catch (const std::logic_error& e)
  {
    std::cerr << "Logic Error: " << e.what() << '
';
    return 1;
  }

  std::cout << sequenceCounter() << '
';
  return 0;
}
