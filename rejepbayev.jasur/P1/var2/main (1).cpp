#include <iostream>
#include <execution>
#include <string>
#include "sequaenceCounter.hpp"

int main()
{
  int tempN;
  std::cin.exceptions(std::cin.failbit);
  number::SequenceCounter seq;
  try
  {
    while ((std::cin >> tempN) && tempN != 0)
    {
      seq(tempN);
      seq.updateAndCountSequence();
    }
    std::cout << seq.getSequenceCount();
    return 0;
  }
  catch (const std::exception&)
  {
    std::cerr << "Invalid sequence input.\n";
    return 1;
  }
  catch (const std::string ex)
  {
    std::cerr << ex;
    return 2;
  }
}
