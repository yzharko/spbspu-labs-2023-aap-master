#include <iostream>
#include <execution>
#include <string>
#include "sequaenceCounter.hpp"

int main()
{
  int tempN;
  std::cin.exceptions(std::cin.failbit);
  number::Sequaence seq;
  try
  {
    while ((std::cin >> tempN) && tempN != 0)
    {
      seq(tempN);
      seq.counterSeq();
    }
    std::cout << seq.answer();
    return 0;
  }
  catch (const std::exception&)
  {
    std::cerr << "it's not sequaence\n";
    return 1;
  }
  catch (const std::string ex)
  {
    std::cerr << ex;
    return 2;
  }
}
