#include <iostream>
#include "FindingSubMax.hpp"

int main()
{
  using namespace khomichenko;
  FindingSubMax FindingSubMax;
  size_t seqCount = 0;
  size_t num = 0;
  std::cin >> num;
  while (std::cin && num != 0)
  {
    ++seqCount;
    FindingSubMax(num);
    std::cin >> num;
  };
  if (!std::cin)
  {
    std::cerr << "not a sequence\n";
    return 1;
  }
  else if (seqCount < 2)
  {
    std::cerr<< "too short sequence\n";
    return 2;
  }
  else
  {
    std::cout << FindingSubMax() << "\n";
    return 0;
  }
};
