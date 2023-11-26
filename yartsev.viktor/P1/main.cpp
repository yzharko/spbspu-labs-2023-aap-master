#include <iostream>
#include <stdexcept>
#include "seqCounter.hpp"

int main ()
{
  int num = 0;
  yartsev::SequenceCounter seqCounter;
  do {
    std::cin >> num;
    if (!std::cin) {
      std::cerr << "Error: Not a sequence\n";
      return 1;
    } else if (num != 0) {
      try {
        seqCounter.updateMaxSequence(num);
        seqCounter.updateMinCounter(num);
      } catch (const std::exception & e) {
        std::cerr << "Error: " << e.what() << "\n";
        seqCounter();
        return 2;
      }
    }
  } while (num != 0);
  seqCounter();
  return 0;
}
