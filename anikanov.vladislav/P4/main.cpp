#include <iostream>
#include <fstream>
#include "arrayModifications.h"
#include "check.h"
#include "errorsPrint.h"
#include "inOutArray.h"

int main(int argc, char **argv)
{
  int num = 0;
  try {
    if (argc != 4) {
      throw std::logic_error("1");
    }
    if (!isNumber(argv[1])) {
      throw std::logic_error("3");
    }
    num = std::stoi(argv[1]);
    if (num != 1 && num != 2) {
      throw std::logic_error("2");
    }
  } catch (const std::exception &e) {
    printErrorByErrcode(std::cerr, e.what());
    return 1;
  }
  std::ifstream cin(argv[2]);
  std::ofstream cout(argv[3]);
  int n = 0, m = 0;
  if (!(cin >> n >> m)) {
    printErrorByErrcode(std::cerr, "2");
    return 1;
  }
  if (n == 0 || m == 0) {
    printErrorByErrcode(std::cout, "2");
    return 0;
  }
  int arrayStatic[n * m];
  int *arrayP = arrayStatic;
  try {
    if (num == 2) {
      int *arrayDynamic = new int[n * m];
      arrayP = arrayDynamic;
    }
    int countReaded = inputArray(cin, arrayP, n, m);
    if (countReaded != n * m) {
      throw std::logic_error("2");
    }
    spiralIncrease(arrayP, n, m);
    printArray(cout, arrayP, n, m);
    if (num == 2) {
      delete[] arrayP;
    }
  } catch (const std::logic_error &err) {
    printErrorByErrcode(std::cout, err.what());
    if (num == 2) {
      delete[] arrayP;
      arrayP = nullptr;
    }
    return 1;
  }
  arrayP = nullptr;
}
