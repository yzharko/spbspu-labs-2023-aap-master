#include <iostream>
#include <stdexcept>
#include "minInSequence.hpp"
#include "sequenceCounter.hpp"

int main ()
{
  int num = 0;
  yartsev::MinInSequenceCounter minCounter;
  yartsev::MaxSequenceCounter maxSeqCounter;
  do {
    std::cin >> num;
    if (!std::cin) {
      std::cerr << "Error: Not a sequence\n";
      return 1;
    } else if (num != 0) {
      try {
        minCounter(num);
        maxSeqCounter(num);
      } catch (const std::exception & e) {
        std::cerr << "Error: " << e.what() << "\n";
        std::cout << minCounter() << " " << maxSeqCounter() << "\n";
        return 2;
      }
    }
  } while (num != 0);
  std::cout << minCounter() << " " << maxSeqCounter() << "\n";
  return 0;
}
