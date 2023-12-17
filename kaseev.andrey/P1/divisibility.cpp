#include "Divisibility.hpp"
#include <iostream>
#include <stdexcept>

kaseev::Divisibility::Divisibility():
    count(0),
    OldNum(),
    NewNum()
{}

int kaseev::Divisibility::operator()(int OldNum, int NewNum)
{
  while (NewNum != 0 && OldNum != 0)
  {
    if (NewNum % OldNum == 0)
    {
      count += 1;
    }
    OldNum = NewNum;
    if (!(std::cin >> NewNum))
    {
      throw std::logic_error("Wrong input");
    }
  }
  return count;
}
void kaseev::Divisibility::operator()(int count)
{
  std::cout << count << "\n";
}
