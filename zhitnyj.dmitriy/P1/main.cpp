#include <iostream>
#include "funcEqlSeq.h"
#include "funcSumDup.h"

int main()
{
  int elm = 0;

  zhitnyj::funcEqlSeq funcEqlSeq;
  zhitnyj::funcSumDup funcSumDup;

  try {
    if (!(std::cin >> elm)) {
      throw std::logic_error("Invalid input");
    }
    while (elm) {
      funcEqlSeq(elm);
      funcSumDup(elm);
      if (!(std::cin >> elm)) {
        throw std::logic_error("Invalid input");
      }
    }
    std::cout << funcEqlSeq() << "\n";
    std::cout << funcSumDup() << "\n";
  } catch (const std::length_error &exc) {
    std::cerr << exc.what() << "\n";
    return 2;
  }
  catch (const std::logic_error &exc) {
    std::cerr << exc.what() << "\n";
    return 1;
  }

  return 0;
}
