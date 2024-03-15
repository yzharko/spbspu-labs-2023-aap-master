#include <iostream>
#include "countEqualMinParticipants.hpp"
#include "countLessThanPrevMoreThanNext.hpp"
#include "countLargerThanPreviousSegments.hpp"

int main()
{
  int value = 0;
  jasur::MinCounter minCounter;
  jasur::LessMoreCounter lessMoreCounter;
  jasur::LargerSegmentsCounter largerSegmentsCounter;
  do
  {
    int prevValue = value;
    std::cin >> value;
    if (!std::cin)
    {
      std::cerr << "Not a valid input.. \n";
      return 1;
    }
    else if (value != 0 && prevValue != 0)
    {
      try
      {
        minCounter.process(value);
        lessMoreCounter.process(value);
        largerSegmentsCounter(value);
      }
      catch (const std::exception &e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  } while (value != 0);
  std::cout << minCounter() << "\n";
  std::cout << lessMoreCounter() << "\n";
  std::cout << largerSegmentsCounter() << '\n';
  return 0;
}
