#include "functionSeqSym.h"
#include "functionDgtSnd.h"
#include "functionStrRead.h"
#include <iostream>

int main()
{
  char* str = nullptr;
  char* str_ = nullptr;

  try
  {
    str = readDynamicString();
    str_ = readDynamicString();

    if (!*str)
    {
      throw std::logic_error("Invalid input!");
    }

    std::cout << strSymbolsRepeats(str) << std::endl;

    char* str1_ = appendNumToStr(str, str_);

    std::cout << str1_ << std::endl;

    delete[] str;
    delete[] str_;
    delete[] str1_;
  }
  catch (const std::logic_error& err)
  {
    std::cerr << err.what() << std::endl;

    delete[] str;
    delete[] str_;
    return 1;
  }
  catch (const std::exception& err)
  {
    std::cerr << err.what() << std::endl;

    delete[] str;
    delete[] str_;
    return 1;
  }

  return 0;
}
